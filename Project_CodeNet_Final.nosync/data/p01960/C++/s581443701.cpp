#include<bits/stdc++.h>
 
using namespace std;
 
using int64 = long long;
const double INF = 1e18;
 
int N, K;
vector< int > g[100000];
int subtree_size[100000];
int dp[100000];
 
int dfs(int idx, int par)
{
  subtree_size[idx] = 1;
  int add = 0, ret = 0;
  vector< int > vs;
  for(auto &to : g[idx]) {
    if(to == par) continue;
    ret = max(ret, dfs(to, idx));
    subtree_size[idx] += subtree_size[to];
    add += subtree_size[to] >= K;
    vs.emplace_back(dp[to]);
  }
  if(vs.empty()) return (0);
  sort(vs.rbegin(), vs.rend());
  dp[idx] = max(add, vs[0] + add - 1);
 
  if(N - subtree_size[idx] >= K) ++add;
  ret = max(ret, vs[0] + add - 1);
  if(g[idx].size() > add) ret = max(ret, add);
  if(vs.size() >= 2) ret = max(ret, vs[0] + vs[1] + add - 2);
  return (ret);
}
 
int main()
{
  cin >> N >> K;
  for(int i = 1; i < N; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b);
    g[b].emplace_back(a);
  }
  cout << dfs(0, -1) << endl;
}