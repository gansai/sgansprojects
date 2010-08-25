#pragma once
#include<cmath>
class Node
{
private:
	int x;
	int y;
public:
	Node();
	Node(int,int);
	
	int getx();
	int gety();
	~Node(void);
};

