#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);
    ~Graph();
    void addEdge(int x, int y);
    void connectedComponents();
};

Graph::Graph(int V){
    this->V=V;
    adj = new list<int>[V];
}
void Graph::addEdge(int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
}

Graph::~Graph(){
    delete[] adj;
}

void Graph::DFSUtil(int v,bool visited[]){
    visited[v] = true;
    cout<< v<<" ";

    list<int>::iterator i;
    for(i =adj[v].begin();i!=adj[v].end();++i){
        if(!visited[*i]){
            DFSUtil(*i,visited);
        }
    }
}

void Graph::connectedComponents(){
    bool *visited = new bool [V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int v=0;v<V;v++){
        if(visited[v]==false){
            DFSUtil(v,visited);
        }
        cout << '\n';
    }
    delete[] visited;
}


int main()
{
     Graph g(5); 
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
 
    cout << "Following are connected components \n";
    g.connectedComponents();
 
    return 0;
}