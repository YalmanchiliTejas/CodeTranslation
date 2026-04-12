#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#include<algorithm>
#include<stack>
#include<set>
#include<numeric>

using namespace std;

int N,M;
int ans=0;
int graph[8][8];

void dfs(int i,int visited[8]);

int main(){
  cin>>N>>M;
  for (int m = 0; m < M; m++) {
    int a;cin>>a;
    int b;cin>>b;
    graph[a-1][b-1]=graph[b-1][a-1]=1;
  }
  int visited[8];
  for(int n=0;n<8;n++){
    visited[n]=0;
  }
  visited[0]=1;
  dfs(0,visited);
  cout<<ans<<"\n";

}

void dfs(int i,int visited[8]){
  for (int j = 0; j < N; j++) {
    if(graph[i][j]==1&&visited[j]==0){
      if(accumulate(visited,visited+N,0)==N-1){
        ans++;
        return;
      }
      visited[j]=1;
      dfs(j,visited);
      visited[j]=0;

    }
  }
}