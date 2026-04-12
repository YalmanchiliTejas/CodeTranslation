#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;

int n, m;
vector<vi> graph;
int ans = 0;

void dfs(int i, set<int> path) {
  if(path.size() == n - 1)
    ans++;
  else {
    path.insert(i);
    for(auto v : graph[i])
      if(!path.count(v)) dfs(v, path);
  }
}

int main() {
  cin >> n >> m;
  graph = vector<vi>(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }
  dfs(0, {});
  cout << ans << endl;
}