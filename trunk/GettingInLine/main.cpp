#include"Node.h"
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<vector>
#include<cstring>

using namespace std;
using std::ios;
vector<Node>NodeColl;
double distMatrix[NodeColl.size()][NodeColl.size()];
int path[NodeColl.size()];
void FindLeastCableLength();
double CableLength(Node a,Node b);
int FindNextNode(int row);
bool Contains(int);
struct ident{
	int id[2];
	double val;
};

int main(int argc,char* argv[]) 
{

	ifstream infile(argv[1]);
	
	string str;
	int i = 0,x,y;
	
	if ( !infile )
	{
		cerr << "File could not be opened" << endl;
		return( -1 );
	}

	while(infile>>str)
	{

		int val = atoi(str.c_str());
		cout<<val<<endl;
		if(val == 0)
			break;
		while(i<val)
		{
			i++;
			infile>>x;
			cout<<"x = "<<x<<endl;
			infile>>y;
			cout<<"y = "<<y<<endl;
			Node n(x,y);
			NodeColl.push_back(n);
		}
		i = 0;
		//call method to process each Collection.
		FindLeastCableLength();
		//flush the vector
		NodeColl.clear();
		
	}	
	infile.close();
	return 0;

}
void FindLeastCableLength()
{
	
	vector<int>::size_type sz = NodeColl.size();
	
	int tempNum,min = 10000;
	int i,j;
	int rowVal;	
	for(int i=0;i<sz;i++)
	{
			
		for(int j=0;j<sz;j++)
		{
			
				double len = CableLength(NodeColl[i],NodeColl[j]);
				cout<<"Length from node"<<i<<" to node"<<j<<" is "<<len<<endl;
				distMatrix[i][j] = len;
				
								
		}			
			
	}
	
		path[0] = 0;
		for(int i=1;i<sz;i++)
		{
		int nextRow = FindNextNode(i-1);
		path[i] = nextRow;
		}
		

}

int FindNextNode(int row)
{
	vector<int>::size_type sz = NodeColl.size();
	struct ident* tempId = (struct ident *)malloc(sizeof(struct ident));
	struct ident* minId = (struct ident *)malloc(sizeof(struct ident));
	int i,j;
	minId->val = 10000;
	minId->id[0] = 0;
	minId->id[1] = 0;
	//sort the array containing values from the row corresponding to 'row'
		for( j =0;j<sz;j++)
		{
			if(distMatrix[row][j] !=0)
				{
				tempId->val = distMatrix[row][j];
			 	tempId->id[0] = row;
				tempId->id[1] = j;
				}
				if(tempId->val < minId->val)
				{
					minId->val = tempId ->val;
					minId->id[0] = row;
					minId->id[1] = j;
						
				}
				
		}
		
	}

	bool Contains(int val)
	{
		vector<int>::size_type sz = NodeColl.size();
		for(int i =0;i<sz;i++)
			if(val == path[i])
				return true;

		return false;
	}
	

	//cout<<"minimum from node"<<i<<" is "<<minId->val<<"to node"<<minId->id[1]<<endl;
	
	
}

double CableLength(Node a,Node b)
{
	double numX = pow(((float)(a.getx()) - (float)(b.getx())),2);
	double numY = pow(((float)(a.gety()) - (float)(b.gety())),2);

	double length = sqrt(numX+numY);

	return length;
}