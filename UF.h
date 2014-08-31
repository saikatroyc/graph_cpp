#include<iostream>
using namespace std;
// implementation of quick union
class UF{
private:
    int V;
    int *id;
    int root(int v);
public:
    UF(int numofVertices);
    ~UF();
    void __union(int v, int w);
    bool __find(int v, int w);
};
