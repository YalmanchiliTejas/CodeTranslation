#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;

int N,M,ans;
bool G[10][10];
bool used[10];

void dfs(int v, int cnt) {
  if(cnt==N) {
    ans++;
    return ;
  }
  used[v]=1;
  rep(i, N) {
    if(!used[i]&&G[v][i]) dfs(i, cnt+1);
  }
  used[v]=0;
}
 
int main() {
  cin>>N>>M;
  rep(i, M) {
    int a,b; cin>>a>>b;
    a--; b--;
    G[a][b]=G[b][a]=true;
  }
  dfs(0,1);
  cout<<ans<<endl;
  return 0;
}
