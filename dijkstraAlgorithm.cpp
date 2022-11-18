// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class graphs
{
    int v;
    list<pair<int,int>> *adj;
    public:
    graphs(int V){
        v=V;
        adj=new list<pair<int,int>> [v];
    }
    void addEdge(int u,int v,int w){
        adj[v].push_back({w,u});
        adj[u].push_back({w,v});
    }
    int dijkstra(int src,int dest){
        vector<int> dist(v,INT_MAX);
        set<pair<int,int>> s;
        
        dist[src]=0;
        s.insert({0,src});
        
        while(!s.empty()){
            auto it=s.begin();
            int node=it->second;
            int currentDist=it->first;
            s.erase(it);
            for(auto nbr : adj[node]){
                int nbrNode=nbr.second;
                int edge=nbr.first;
                if(currentDist+edge < dist[nbrNode]){
                    auto f=s.find({dist[nbrNode],nbrNode});
                    
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbrNode]=currentDist+edge;
                    s.insert({dist[nbrNode],nbrNode});
                }
            }
        }
        
        
        return dist[dest];
    }
};
int main() {
   graphs g(5);
   	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;

    return 0;
}
