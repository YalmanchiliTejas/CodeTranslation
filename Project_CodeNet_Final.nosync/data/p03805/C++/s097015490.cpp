#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> graph;
const long long mod = 1000000007LL;

int n, m;
int ans;

void dfs(int v, vi vec, vector<bool> seen, graph &g) {
  if(seen[v]) return;
  if(vec.size()==n) {
    ans++;
    return;
  }
  seen[v] = true;
  vec.push_back(v);
  for(auto to : g[v]) {
    vector<bool> seen2 = seen;
    dfs(to,vec,seen2,g);
  }
}

int main() {
  cin >> n >> m;
  ans = 0;
  graph g(n);
  rep(i,m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> seen(n,false);
  dfs(0,{0},seen,g);
  cout << ans << endl;
  return 0;
}