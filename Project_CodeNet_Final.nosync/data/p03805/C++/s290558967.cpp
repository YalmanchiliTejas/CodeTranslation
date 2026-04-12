#include <bits/stdc++.h>
using namespace std;
int n, m;
int used[8];
int connect[8][8];
int dfs(int now, int depth){
  if(used[now]) return 0;
  if(depth == n) return 1;
  used[now] = 1;
  int ans = 0;
  for(int i=0; i<n; i++){
    if(connect[now][i]) ans += dfs(i, depth+1);
  }
  used[now] = 0;
  return ans;
}

int main() {
  cin >> n >> m;
  int a[m], b[m];
  for(int i=0; i<m; i++){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  for(int i=0; i<m; i++){
    connect[a[i]][b[i]] = connect[b[i]][a[i]] = 1;
  }
  cout << dfs(0, 1) << endl;
}