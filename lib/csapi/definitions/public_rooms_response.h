/******************************************************************************
 * THIS FILE IS GENERATED - ANY EDITS WILL BE OVERWRITTEN
 */

#pragma once

#include "converters.h"

#include <QtCore/QVector>

namespace Quotient
{

// Data structures

struct PublicRoomsChunk
{
    /// Aliases of the room. May be empty.
    QStringList aliases;
    /// The canonical alias of the room, if any.
    QString canonicalAlias;
    /// The name of the room, if any.
    QString name;
    /// The number of members joined to the room.
    int numJoinedMembers;
    /// The ID of the room.
    QString roomId;
    /// The topic of the room, if any.
    QString topic;
    /// Whether the room may be viewed by guest users without joining.
    bool worldReadable;
    /// Whether guest users may join the room and participate in it.If they can,
    /// they will be subject to ordinary power levelrules like any other user.
    bool guestCanJoin;
    /// The URL for the room's avatar, if one is set.
    QString avatarUrl;
};

template <>
struct JsonObjectConverter<PublicRoomsChunk>
{
    static void dumpTo(QJsonObject& jo, const PublicRoomsChunk& pod);
    static void fillFrom(const QJsonObject& jo, PublicRoomsChunk& pod);
};

/// A list of the rooms on the server.
struct PublicRoomsResponse
{
    /// A paginated chunk of public rooms.
    QVector<PublicRoomsChunk> chunk;
    /// A pagination token for the response. The absence of this tokenmeans
    /// there are no more results to fetch and the client shouldstop paginating.
    QString nextBatch;
    /// A pagination token that allows fetching previous results. Theabsence of
    /// this token means there are no results before thisbatch, i.e. this is the
    /// first batch.
    QString prevBatch;
    /// An estimate on the total number of public rooms, if theserver has an
    /// estimate.
    Omittable<int> totalRoomCountEstimate;
};

template <>
struct JsonObjectConverter<PublicRoomsResponse>
{
    static void dumpTo(QJsonObject& jo, const PublicRoomsResponse& pod);
    static void fillFrom(const QJsonObject& jo, PublicRoomsResponse& pod);
};

} // namespace Quotient
