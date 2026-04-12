#include <bits/stdc++.h>
using namespace std;
const int nmax=10;
bool graph[nmax][nmax];  


int dsp(int viNodes,int nownode,bool visited[nmax],int N){
  
  visited[nownode]=true;
  
  int ret=0;
  for(int i=0;i<N;i++){
    if(visited[i])continue;
    if(!graph[nownode][i])continue;
    
    if(viNodes==N-1){  
      visited[nownode]=false;
      return 1;
    }
    ret+=dsp(viNodes+1,i,visited,N);
  }
  
  visited[nownode]=false;
  return ret;
}


int main(void)
{
  int i,j;
  int N,M;
  bool visited[nmax]={};
  cin>>N>>M;
  
  for(i=0;i<N;i++)visited[i]=false;
  for(int ai=0;ai<M;ai++){
    cin>>i>>j;
    graph[i-1][j-1]=true;
    graph[j-1][i-1]=true;
  }
  
  cout <<dsp(1,0,visited,N)<< endl;
  return 0;
}



