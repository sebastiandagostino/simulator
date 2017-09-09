#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <unordered_map>

#include "NodeState.h"

/**
 * A message sent from one node to another, containing the positions taken
 */
class Message {

private:

    int fromNodeId;

    int toNodeId;

    std::unordered_map<int, NodeState> data;

public:

    Message(int fromNodeId, int toNodeId);

    Message(int fromNodeId, int toNodeId, const std::unordered_map<int, NodeState>& data);

    int getFromNodeId() const;

    int getToNodeId() const;

    bool hasEmptyData() const;

    void insertData(int nodeId, signed char status);

    const std::unordered_map<int, NodeState>& getData() const;

    void addPositions(const std::unordered_map<int, NodeState>& data);

    void subPositions(const std::unordered_map<int, NodeState>& data);

};

#endif /* MESSAGE_H_ */
