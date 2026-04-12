#include<bits/stdc++.h>
#include<iostream>
using namespace std;

bool graph[8][8];

int DFS(int x,int N,bool visited[8]){
  
  bool allvisited=true;
  for(int i=0;i<N;i++){
    if(visited[i]==false) allvisited=false;
  }
  if(allvisited==true) return 1;
  
  int ans=0;
  
  for(int i=0;i<N;i++){
    if(graph[x][i]==false) continue;
    if(visited[i]) continue;
    
    visited[i]=true;
    ans+=DFS(i,N,visited);
    visited[i]=false;
  }
  return ans;
}

int main(void){
  int N,M;
  cin >> N >> M;
  for(int i=0;i<M;i++){
    int A,B;
    cin >> A >> B;
    graph[A-1][B-1]=graph[B-1][A-1]=true;
  }
  
  bool visited[8];
  for(int i=0;i<N;i++){
    visited[i]=false;
  }
  visited[0]=true;
  
  cout << DFS(0,N,visited) << endl;
  return 0;
}
