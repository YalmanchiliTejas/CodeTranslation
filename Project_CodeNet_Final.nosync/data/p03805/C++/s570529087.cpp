#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int n, m;
bool g[10][10];
bool h[10];
int res = 0;

void dfs(int i){
  bool flag = true;
  rep(j, n){
    if(!h[j]){
      flag = false;
    }
  }
  if(flag){
    res++;
    return;
  }
  rep(j, n){
    if(g[i][j] && !h[j]){
      h[j] = true;
      cerr << i << " "<< j << endl;
      dfs(j);
      h[j] = false;
    }
  }
}

int main(){
  cin >> n >> m;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    g[a - 1][b - 1] = g[b - 1][a - 1] = true;
  }
  rep(i, n) h[i] = 0;
  rep(i, n){rep(j, n)cerr << g[i][j];cerr << endl;}
  h[0] = true;
  dfs(0);
  cout << res << endl;
  return 0;
}