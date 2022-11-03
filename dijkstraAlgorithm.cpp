// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class graphs
{
    int v;
    list<pair<int,int>> *g;
 
  public :
      graphs(int V){
          v=v;
          g=new list<pair<int,int>> [v];
      }
      void addEdge(int u,int v,int wt){
          g[u].push_back({v,wt});
          g[v].push_back({u,wt});
      }
      int dijkstra(int scr,int dest){
          vector<int> distance(v,INT_MAX);
          set<pair<int,int>> s;
          distance[scr]=0;
          s.insert({0,scr});
          while(!s.empty()){
              auto it=s.begin();
              int node=it->second;
              int nodeDist=it->first;
              s.erase(it);
              for(auto nbr : g[node]){//nbr=neighbour node
                  int nbrNode=nbr.second;
                  int currentEdge=nbr.first;
                  if(nodeDist+currentEdge < distance[nbrNode]){
                      auto f=s.find({distance[nbrNode],nbrNode});
                      if(f!=s.end()){
                          s.erase(f);
                      }
                      distance[nbrNode]=nodeDist+currentEdge;
                      s.insert({distance[nbrNode],nbrNode});
                  }
              }
          }
         
		}
		 	for(int i=0;i<v;i++){
			cout<<"Node i "<<i <<" Dist "<<distance[i] <<endl;}
          return distance[dest];
      }
};
int main(){

	graphs g(5);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,4)<<endl;
}
