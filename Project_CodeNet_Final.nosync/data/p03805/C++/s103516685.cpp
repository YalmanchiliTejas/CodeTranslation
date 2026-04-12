#include <bits/stdc++.h>
using namespace std;

int n,m,ans;
vector<vector<bool>>data(8,vector<bool>(8,false));

void dfs(int v,int p,int c,vector<bool>used){
  for(int i = 0;i < n;i++){
    if(i != p && data[v][i] && !used[i]){
      used[v] = true;
      dfs(i,v,c+1,used);
    }
  }
  if(c == n) ans++;
}
int main() {
  ans = 0;
  cin >> n >> m;
  for(int i = 0;i < m;i++){
    int a,b;
    cin >> a >> b;
    a--;b--;
    data[a][b] = true;
    data[b][a] = true;
  }
  vector<bool>st(8,false);
  dfs(0,-1,1,st);
  cout << ans << endl;
}
