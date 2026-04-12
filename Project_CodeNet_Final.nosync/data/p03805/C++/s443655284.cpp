#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define reps(i,a,b) for(int i= a; i < b; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
vector<vector<int>> graph;
int n, m;
int ans = 0;

void dfs(int stp, int cv, vector<int> &seen) {
  seen.at(cv) = 1;
  if (stp == n - 1) {
    if (count(ALL(seen), 1) == n) ans++;
    seen.at(cv) = 0;
    return;
  }
  for (int nv : graph.at(cv)) {
    if (seen.at(nv)) continue;

    dfs(stp+1, nv, seen);
  }
  seen.at(cv) = 0;
  return;
}

int main()
{
  cin >> n >> m;
  graph.resize(n, vector<int>());
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    graph.at(y).push_back(x);
    graph.at(x).push_back(y);
  }
  vector<int> seen(n, 0);
  dfs(0, 0, seen);
  cout << ans << endl;

  
  
  return 0;
}