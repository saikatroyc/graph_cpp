#include<iostream>
#include "graph.h"

void printQueue(queue<edge> &q);
int main() {
    graph g(6);
    g.addEdge(0,1,4);
    g.addEdge(0,2,1);
    g.addEdge(1,2,2);
    g.addEdge(1,3,5);
    g.addEdge(1,4,6);
    g.addEdge(2,3,3);
    g.addEdge(3,5,7);
    g.printEdges();
    queue<edge> q = g.runKruskal();
    printQueue(q);
    g.BFS(0);
    g.DFS(0);
    return 0;
}

void printQueue(queue<edge> &q) {
	cout<<"kruskal o/p:"<<endl;
	while(!q.empty()) {
		edge e = q.front();
		q.pop();
		int v = e.getEither();
		int w = e.getOther(v);
		cout<<v<<"--"<<w<<"("<<e.getWeight()<<")"<<endl;
	}
}
