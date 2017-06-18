#include <cassert>

#include "Network.h"

Network::Network() :
	masterTime(0) {
}

int Network::getMasterTime() const {
	return masterTime;
}

void Network::setMasterTime(int masterTime) {
	this->masterTime = masterTime;
}

void Network::sendMessage(const Message& message, Link& link, int sendTime) {
	assert(message.getToNodeId() == link.getToNodeId());
	link.setSendTime(sendTime);
	link.setMessages(messages[link.getReceiveTime()].addMessage(message));
}

int Network::countMessages() const {
	return messages.size();
}

std::map<int, Event>& Network::getMessages() {
	return messages;
}
