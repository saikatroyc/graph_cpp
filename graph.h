#include<iostream>
#include<list>
#include<queue>
#include "UF.h"
using namespace std;
class edge {
    int v;
    int w;
    int weight;
public:
    int getWeight() {
        return weight;
    }
    int getEither() {
        return v;
    } 
    int getOther(int v) {
        if (this->v == v) return this->w;
        return this->v;
    }
    edge(int v, int w, int weight) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }
};

class compare {
public:
    bool operator () (edge& e1, edge& e2) {
        return e1.getWeight() > e2.getWeight();
    } 
};
class graph {
    list<edge> **adj;
    list<edge> E;
    int V;
    UF createUnion();
    void DFS_util(int vertex, bool visited[]);
public:
    graph(int V);
    void addEdge(int v, int w, int weight);
    queue<edge> runKruskal();
    void printEdges();
    void BFS(int vertex);
    void DFS(int vertex);
};
