#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int path(int a,vector<int> adj[],int n,int s,int* dist){   //function to evaluate the path of a given node from source node
         bool got = false;    //variable to check source node is reached or not
         for(int k=0;k<adj[a].size();k++){
              if(adj[a][k] == s){
                 cout<<s<<" ";
                 got = true;
              }
              if(!got && k==adj[a].size()-1) {    //if source node is not connected to given node 
                 path(adj[a][0],adj,n,s,dist);    //take a node connected to given node and search for source node
              }
         }
          (*dist)++;  //length from given node to source incremented for every edge
         cout<<a<<" ";  //printing all other vertices in the path
   return *dist;  
}
int main(){
  int n,m,s;
  cin>>n>>m>>s;        //n: number of vertices,m: number of edges,s: source vertex
  vector<int> adj[n];  //adjacency list of each vertex
  for(int i=0;i<m;i++){
    int a,b;                    //loop to initialise adjacency list
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }                                                               
  queue<int> curr;     //currently visited but still not traversed vertices
  int vsd[n] ={0};     //visited array
  curr.push(s);        //visited source but not traversed it
  vsd[s] = 1;          
  int var = s;         //variable to iterate over all vertices in bfs order
  int temp =0;         // index for visited array
  int dist=0;          // variable to store distance from given node to source
  int pie[n]={0};         //array to store bfs traversal of nodes 
  int tidx=0;             //temporary index for pie array                                             
  while(var<=n){       //bfs traversal loop
  for(int k = 0;k < adj[var].size();k++){ 
     temp = adj[var][k];          //go through adjacency list of given vertex
    if(vsd[temp] == 0 ){           
       vsd[temp] = 1;            //if it's not visited visit it and add it to current queue
       curr.push(temp);
    }
  }
    curr.pop();                 //pop first element in queue hence it's traversed
    var = curr.front();         //Update var to first element in queue(still not traversed)
    if(var<=n){               
    pie[tidx] = var;            //array that stores bfs traversal of graph
    tidx++;
    }  
}
 for(int y=0;y<n-1;y++){
     dist = path(pie[y],adj,n,s,&dist);   //loop to print given output format
     cout<<dist<<endl;
     dist =0;
 }

     }
  
      