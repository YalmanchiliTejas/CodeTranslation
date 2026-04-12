#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int MAX;
vector<int> g[10];
int dfs(int u=0, int b=0){
  if(b>>u&1) return 0;
  b ^= 1<<u;
  if(b==MAX) return 1;
  int res = 0;
  for(int v:g[u]) res += dfs(v,b);
  return res;
}
int main() {
  int n,m;
  cin >> n >> m;
  MAX = (1<<n)-1;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  cout << dfs() << endl;
}
