#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <ios>     // std::left, std::right
#include <iomanip> // std::setw(int), std::setfill(char)
using namespace std;

int dfs(int v,int N,bool visited[10],int gp[10][10]){
  bool all_visited=true;

  for(int i=0;i<N;++i){
    if(visited[i]==false){
      all_visited=false;
    }
  }

  if(all_visited){
    return 1;
  }

  int ret=0;

  for(int i=0;i<N;++i){
    if(gp[v][i]==0 || visited[i]){
      continue;
    }
    visited[i]=true;
    ret+=dfs(i,N,visited,gp);
    visited[i]=false;
  }
  return ret;
}

int main(){
  int N,M,a,b;
  cin>>N>>M;
  int gp[10][10]={};
  //グラフを設定
  for(int i=0;i<M;++i){
    cin>>a>>b;
    gp[a-1][b-1]=1;
    gp[b-1][a-1]=1;
  }
  bool visited[10];
  for(int i=0;i<N;++i){
    visited[i]=false;
  }
  visited[0]=true;
  cout<<dfs(0,N,visited,gp)<<"\n";
return 0;
}
