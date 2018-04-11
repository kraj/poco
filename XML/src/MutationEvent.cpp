//
// MutationEvent.cpp
//
// Library: XML
// Package: DOM
// Module:  DOMEvents
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/DOM/MutationEvent.h"
#include "Poco/DOM/Document.h"


namespace Poco {
namespace XML {


const XMLString MutationEvent::DOMSubtreeModified          = toXMLString("DOMSubtreeModified");
const XMLString MutationEvent::DOMNodeInserted             = toXMLString("DOMNodeInserted");
const XMLString MutationEvent::DOMNodeRemoved              = toXMLString("DOMNodeRemoved");
const XMLString MutationEvent::DOMNodeRemovedFromDocument  = toXMLString("DOMNodeRemovedFromDocument");
const XMLString MutationEvent::DOMNodeInsertedIntoDocument = toXMLString("DOMNodeInsertedIntoDocument");
const XMLString MutationEvent::DOMAttrModified             = toXMLString("DOMAttrModified");
const XMLString MutationEvent::DOMCharacterDataModified    = toXMLString("DOMCharacterDataModified");


MutationEvent::MutationEvent(Document::Ptr&& pOwnerDocument, const XMLString& type):
	Event(std::move(pOwnerDocument), type, 0, true, false),
	_change(MODIFICATION),
	_pRelatedNode(0)
{
}


MutationEvent::MutationEvent(Document::Ptr&& pOwnerDocument, const XMLString& type, EventTarget::Ptr&& pTarget, bool canBubble, bool cancelable, Node::Ptr relatedNode):
	Event(std::move(pOwnerDocument), type, std::move(pTarget), canBubble, cancelable),
	_change(MODIFICATION),
	_pRelatedNode(relatedNode)
{
}


MutationEvent::MutationEvent(Document::Ptr&& pOwnerDocument, const XMLString& type, EventTarget::Ptr&& pTarget, bool canBubble, bool cancelable, Node::Ptr relatedNode,
	                         const XMLString& prevValue, const XMLString& newValue, const XMLString& attrName, AttrChangeType change):
	Event(std::move(pOwnerDocument), type, std::move(pTarget), canBubble, cancelable),
	_prevValue(prevValue),
	_newValue(newValue),
	_attrName(attrName),
	_change(change),
	_pRelatedNode(relatedNode)
{
}


MutationEvent::~MutationEvent()
{
}


void MutationEvent::initMutationEvent(const XMLString& type, bool canBubble, bool cancelable, Node::Ptr relatedNode,
	                                  const XMLString& prevValue, const XMLString& newValue, const XMLString& attrName, AttrChangeType change)
{
	initEvent(type, canBubble, cancelable);
	_pRelatedNode = relatedNode;
	_prevValue    = prevValue;
	_newValue     = newValue;
	_attrName     = attrName;
	_change       = change;
}

	
} } // namespace Poco::XML
