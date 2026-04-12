#include <bits/stdc++.h>
using namespace std;

bool edge[8][8];
bool visited[8];

int dfs(int N,int now,bool visited[]){
  int ans=0;
  bool allv=true;
  for (int i=0;i<N;i++){
    if (visited[i]==false){
      if (edge[now][i] or edge[i][now]){
        visited[i]=true;
        ans+=dfs(N,i,visited);
        visited[i]=false;
      }
      allv=false;
    }
  }
  if (allv){
    return 1;
  }
  return ans;
}
int main(){
  int N,M;
  cin >> N >> M;
  int a,b;
  for (int i=0;i<M;i++){
    cin >> a >> b;
    edge[a-1][b-1]=true;
  }
  visited[0]=true;
  cout << dfs(N,0,visited) << endl;
}