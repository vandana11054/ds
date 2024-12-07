#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
  int n,m,s;
  cin>>n>>m>>s;           //n: number of vertices,m: number of edges,s: source vertex
  vector<int> adj[n];       //adjacency list of each vertex
  int color[n] = {0};       //array to store color  of each vertex
  for(int i=0;i<m;i++){           //loop to initialise adjacency list
    int a,b;                     
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int temp =0;           //variable  to store every vertex value
  queue<int> curr;       //currently visited but still not traversed vertices
  curr.push(s);          //visited source but not traversed it
  int vsd[n] =  {0};     //visited array
  color[s] = 1;          //coloring source vertex
  int var = s;           //variable to traverse color array
  bool breaks = false;    //validates if a graph is non-bipartite or not
  while(var<=n){
   int k=0;                        //traversal loop among given edges
   for(;k < adj[var].size();k++){ 
     temp = adj[var][k];
    if(vsd[temp] == 0){
    curr.push(temp);
    vsd[temp] =1;
    }
    if (color[temp] == 0){                
       color[temp] = ((color[var]==1) ? 2 : 1);   //color each vertex alternate to color of it's connected vertices
       }
       else{
         if(color[temp] == color[var]){         //If two adjacent vertices are of same color
          cout<< " No path exist "<<endl;
          breaks = true;
         }
         if(color[temp] != color[var]) continue;   //if two adjacent vertices are of different color
       }
   }
   if(breaks) break;
   curr.pop();       //pop first element of queue
   var = curr.front();   //Update var to first element of queue(still not traversed)
   }
  if(!breaks) cout<<" YES "<<endl;   //Graph is bipartite
}