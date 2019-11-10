/******************************************************************************
 * Copyright (C) 2017 Kitsune Ral <kitsune-ral@users.sf.net>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 */

#pragma once

#include "roomevent.h"

namespace Quotient {
class RedactionEvent : public RoomEvent {
public:
    DEFINE_EVENT_TYPEID("m.room.redaction", RedactionEvent)

    explicit RedactionEvent(const QJsonObject& obj) : RoomEvent(typeId(), obj)
    {}

    [[deprecated("Use redactedEvents() instead")]]
    QString redactedEvent() const
    {
        return fullJson()["redacts"_ls].toString();
    }
    QStringList redactedEvents() const
    {
        const auto evtIdJson = contentJson()["redacts"_ls];
        if (evtIdJson.isArray())
            return fromJson<QStringList>(evtIdJson); // MSC2244: a list of ids
        if (evtIdJson.isString())
            return { fromJson<QString>(evtIdJson) }; // MSC2174: id in content
        return { fullJson()["redacts"_ls].toString() }; // legacy fallback
    }
    QString reason() const { return contentJson()["reason"_ls].toString(); }
};
REGISTER_EVENT_TYPE(RedactionEvent)
} // namespace Quotient
