#pragma once
#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Vertex.h"
using namespace std;

template<typename V, typename E>
class Vertex;

template<typename V, typename E>
class Edge
{
public:
	Edge();
	Edge(E inData, Vertex<V, E> * inDest);
	~Edge();
public:
	Edge(const Edge<V, E> & inCopy);
	Edge<V, E> & operator=(const Edge<V, E> & inRhs);
	bool operator==(const Edge<V, E>& inRhs);
public:
	void setEdgeData(E inData) { edgeData = inData; }
	void setEdgeDestination(Vertex<V, E> inDestination) {  }
public:
	E getEdgeData() const { return edgeData; }
	Vertex<V, E> * getEdgeDestination() const { return m_edgeDestination; }

private:
	E edgeData;
	Vertex<V, E> * m_edgeDestination;
};

template<typename V, typename E>
inline Edge<V, E>::Edge()
{
	edgeData = 0;
	m_edgeDestination = new Vertex<V, E>(nullptr);
}

template<typename V, typename E>
inline Edge<V, E>::Edge(E inData, Vertex<V, E> * inDest)
{
	edgeData = inData;
	m_edgeDestination = inDest;
}

template<typename V, typename E>
inline Edge<V, E>::~Edge()
{
	m_edgeDestination = nullptr;
}

template<typename V, typename E>
inline Edge<V, E>::Edge(const Edge<V, E>& inCopy)
{
	m_edgeDestination = inCopy.getEdgeDestination();
	edgeData = inCopy.getEdgeData();
}

template<typename V, typename E>
inline Edge<V, E>& Edge<V, E>::operator=(const Edge<V, E>& inRhs)
{
	if (this != &inRhs) {
		edgeData = inRhs.edgeData;
		m_edgeDestination = inRhs.m_edgeDestination;
	}
	return *this;
}

template<typename V, typename E>
inline bool Edge<V, E>::operator==(const Edge<V, E>& inRhs)
{
	bool result = false;
	if(edgeData == inRhs.getEdgeData() && m_edgeDestination->getVertData() == inRhs.getEdgeDestination()->getVertData())
	{
		result = true;
	}
	return result;
}

#endif

