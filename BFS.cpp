#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
		int key;
		Node(int s)
		{
			this->key=s;
		}
};
class Graph
{
	int V;
	vector<int> *adj;
	vector<Node *>	nodes;
	public:
		Graph(int v);
		void addEdge(int v,int w);
		void BFS(int s);//s is source
};

Graph::Graph(int v)
{
	this->V=v;
	adj=new vector<int>[v];
	for(int i=0;i<v;i++)
	{
		Node *node=new Node(i);
		nodes.push_back(node);
	}
}

void Graph::addEdge(int v,int w)
{
	adj[v].push_back(w);
	//adj[w].push_back(v);
}

void Graph::BFS(int s)
{
	char color[V];
	for(int i=0;i<V;i++)
		color[i]='w';//w=white,g=grey,b=black;
	
	color[s]='g';		
	queue<int> q;
	q.push(s);
	Node *node;
	int v;
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		node=nodes[v];
		cout<<node->key<<" ";
		for(int i=0;i<adj[v].size();i++)
		{
			if(color[adj[v][i]]=='w')
			{
				color[adj[v][i]]='g';
				q.push(adj[v][i]);
			}	
		}
		color[v]='b';	
	}
}
int main()
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 
	

