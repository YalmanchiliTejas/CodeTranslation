#include<bits/stdc++.h>
using namespace std;
int n, m, ans = 0;
int adj[10][10], a, b;

void dfs(int u, int c[]){
  int cc[n+1];
  for ( int i = 1; i <= n; i++){
    cc[i] = c[i];
  }
  cc[u] = 1;
  for ( int i = 1; i <= n; i++){
    if ( adj[u][i] && !cc[i]){
      dfs(i, cc);
    }
  }
  for ( int i = 1; i <= n; i++){
    if( !cc[i] ){
       return ;
    }
  }
  ans++;
  return ;
}

int main(){
  cin >> n >> m;
  for ( int i = 0; i < m; i++){
    cin >> a >> b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }

  int c[n+1];
  for (int i = 1; i <= n; i++){
    c[i] = 0;
  }

  dfs(1, c);

  cout << ans << endl;

  return 0;
}