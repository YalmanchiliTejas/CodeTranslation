#include<bits/stdc++.h>
using namespace std;
#define int long long

int G[10][10];

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n,m; cin >> n >> m;
  //vector<int> G[n];
  for(int i = 0; i < m; i++){
    int a,b; cin >> a >> b;
    a--,b--;
    G[a][b] = G[b][a] = 1;
  }

  vector< vector<int> > dp(1 << n,vector<int> (n,0));
  for(int i = 0; i < n; i++){
    dp[(1 << n) - 1][i] = 1;
  }
  function< int(int,int) > rec =
  [&](int S,int u){
    if(dp[S][u] != 0) return dp[S][u];

    int res = 0;
    for(int i = 0; i < n; i++){
      if(!(S >> i & 1) && G[u][i]){
        res += rec(S | 1 << i,i);
      }
    }
    return dp[S][u] = res;
  };
  cout << rec(1,0) << endl;

  return 0;
}
