//
// Comment.cpp
//
// Library: XML
// Package: DOM
// Module:  DOM
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "Poco/DOM/Comment.h"
#include "Poco/DOM/Document.h"


namespace Poco {
namespace XML {


const XMLString Comment::NODE_NAME = toXMLString("#comment");


Comment::Comment(Document::Ptr&& pOwnerDocument, const XMLString& data):
	CharacterData(std::move(pOwnerDocument), data)
{
}


Comment::Comment(Document::Ptr&& pOwnerDocument, const Comment& comment):
	CharacterData(std::move(pOwnerDocument), comment)
{
}


Comment::~Comment()
{
}


const XMLString& Comment::nodeName() const
{
	return NODE_NAME;
}


unsigned short Comment::nodeType() const
{
	return Node::COMMENT_NODE;
}


Node::Ptr Comment::copyNode(bool deep, Document::Ptr pOwnerDocument) const
{
	return new Comment(std::move(pOwnerDocument), *this);
}


} } // namespace Poco::XML
