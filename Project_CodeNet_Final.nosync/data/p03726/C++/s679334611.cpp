#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<vector<int>> adj;
bool ok = true;
vector<int> v;

int dfs(int n=0, int p=-1) {
  int result = 1, count = 0;
  for (auto x: adj[n]) {
    if (x!=p) {
      v[x] = !v[n];
      int tmp = dfs(x,n);
      result += tmp;
      count += tmp%2;
    }
  }
  if (count>=2) ok = false;
  return result;
}

int main() {
  int N; cin >> N;
  adj.resize(N);
  v.resize(N,-1); v[0] = 0;
  rep(i,N-1) {
    int a, b; cin >> a >> b; a--; b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs();
  int oe = 0; rep(i,N) oe += v[i] ? 1 : -1;
  if (oe) ok = false;
  string result = (!ok) ? "First" : "Second";
  cout << result << endl;
  return 0;
}