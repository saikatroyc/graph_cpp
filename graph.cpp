#include"graph.h"
using namespace::std;
//list<edge*> **adj;
//list<edge> E;
//int V;
graph::graph(int v) {
    this->V = v;
    adj = new list<edge> *[v];
}
void graph::addEdge(int v, int w, int weight) {
    edge e(v,w,weight);
    if (adj[v] == NULL) adj[v] = new list<edge>;
    if (adj[w] == NULL) adj[w] = new list<edge>;
    adj[v]->push_front(e);
    adj[w]->push_front(e);
    E.push_back(e); 
}

void graph::printEdges() {
    list<edge>::iterator it;
    // store all edges in a min heap PQ
    for (it = this->E.begin(); it != this->E.end(); it++) {
        int v = it->getEither();
        int w = it->getOther(v);
        cout<<v<<"--"<<w<<"("<<it->getWeight()<<")"<<endl;     
    }
}

queue<edge> graph::runKruskal() {
    queue<edge> mst;
    priority_queue<edge, vector<edge> , compare> pq;
    list<edge>::iterator it;
    // store all edges in a min heap PQ
    for (it = this->E.begin(); it != this->E.end(); it++) {
        pq.push(*it);
    }

    UF u(this->V);
    //UF u = createUnion();
    while(!pq.empty()) {
        edge e = pq.top();
        pq.pop();
        int v = e.getEither();
        int w = e.getOther(v);
        if (!u.__find(v,w)) {
            u.__union(v,w);
            mst.push(e);
            //cout<<v<<"--"<<w<<"("<<e.getWeight()<<")"<<endl;
        }
    }
    return mst;
}

UF graph::createUnion() {
    UF u(this->V);
    // for all edges in graph, create a union DS
    list<edge>::iterator it;
    for (it = this->E.begin(); it != this->E.end(); it++) {
        int v = it->getEither();
        int w = it->getOther(v);
        u.__union(v, w);
    }
}



void graph::BFS(int vertex) {
	// init all vertex as visited
	cout << "*****BFS*******\n";
	bool *visited = new bool[V];
	deque<int> q;
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}

	visited[vertex] = true;
	q.push_back(vertex);
	while(!q.empty()) {
		int item = q.front();
        cout<<item<<"--";
		q.pop_front();
		list<edge>::iterator it;
		for (it = adj[item]->begin(); it != adj[item]->end();it++) {
            int v = it->getEither();
            int other;
            if (v == item) other = it->getOther(v);
            else other = v;
			if(visited[other] == false) {
				q.push_back(other);
				visited[other] = true;
			}
		}
	}
	cout<<endl;
    delete visited;
}

void graph::DFS(int vertex) {
    bool *visited = new bool[V];
    cout << "*****DFS*******\n";
    DFS_util(vertex, visited);
    delete visited;
}

void graph::DFS_util(int vertex, bool visited[]){
	if (adj[vertex] == NULL) return;
    visited[vertex] = true;
    cout<<vertex<<"--";
    list<edge>::iterator it;
    for (it = adj[vertex]->begin(); it != adj[vertex]->end(); it++) {
    	int v = it->getEither();
    	int other;
		if (v == vertex) other = it->getOther(v);
		else other = v;
        if (visited[other] == false) {
            DFS_util(other, visited);
        }
    }
}
