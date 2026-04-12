#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#include <string>
#include <cstring>
#include <numeric>
#include <cstdlib>
#include <cmath>
using namespace std;

typedef long long ll;

#define INF 10e10
#define rep(i,n) for(int i=0; i<n; i++)
#define rep_r(i,n,m) for(int i=m; i<n; i++)
#define END cout << endl
#define MOD 1000000007
#define pb push_back
// 昇順sort
#define sorti(x) sort(x.begin(), x.end())
// 降順sort
#define sortd(x) sort(x.begin(), x.end(), std::greater<int>())

bool visited[9];
ll ans = 0;
vector<int> point[9];
int n,m;

void dfs(int x) {
  visited[x] = true;

  for (auto to : point[x]) {
    // 次
    if (!visited[to]) {
      dfs(to);
    }
  }

  bool flag = true;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      visited[x] = false;
      return;
    }
  }
  visited[x] = false;
  ans += 1;
  return;
}


int main() {
  cin >> n >> m;

  rep(i,m) {
    int a,b; cin >> a >> b;
    point[a].pb(b);
    point[b].pb(a);
  }

  dfs(1);
  cout << ans << endl;
}
