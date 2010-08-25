#include "Node.h"


Node::Node()
{
	x = 0;
	y = 0;
}

Node::Node(int ax,int ay)
{
	x = ax;
	y = ay;
}

int Node::getx()
{
	return x;	
}

int Node::gety()
{
	return y;
}


Node::~Node(void)
{
}
