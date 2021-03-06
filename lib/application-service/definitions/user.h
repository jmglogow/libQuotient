/******************************************************************************
 * THIS FILE IS GENERATED - ANY EDITS WILL BE OVERWRITTEN
 */

#pragma once

#include "converters.h"

#include <QtCore/QJsonObject>

namespace Quotient
{

// Data structures

struct ThirdPartyUser
{
    /// A Matrix User ID represting a third party user.
    QString userid;
    /// The protocol ID that the third party location is a part of.
    QString protocol;
    /// Information used to identify this third party location.
    QJsonObject fields;
};

template <>
struct JsonObjectConverter<ThirdPartyUser>
{
    static void dumpTo(QJsonObject& jo, const ThirdPartyUser& pod);
    static void fillFrom(const QJsonObject& jo, ThirdPartyUser& pod);
};

} // namespace Quotient
