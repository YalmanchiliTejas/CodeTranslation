#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <fstream>
#define debug(x) cout << #x << " = " << x << endl
#define FOR(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define repr(i,n) for(int i = (n); i > -1; i--)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;

int g[55][55];
int n,m;
int a[55],b[55];
int ans = 0;

void dfs(int x, vector<int> v) {
  bool visited[9] = {false};
  rep(i, v.size()) {
    visited[v[i]] = true;
  }
  bool flag = true;
  FOR(i, 1, n+1) if(!visited[i]) flag = false;
  if(flag) ans++;
  FOR(i, 1, n + 1) {
    if(g[x][i] && !visited[i]) {
      vector<int> vv = v;
      vv.push_back(i);
      dfs(i, vv);
    }
  }
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>n>>m;
  rep(i,55) {
    rep(j,55) g[i][j] = 0;
  }
  rep(i,m) {
    cin>>a[i]>>b[i];
    g[a[i]][b[i]] = 1;
    g[b[i]][a[i]] = 1;
  }
  vector<int> al;
  al.push_back(1);
  dfs(1, al);
  cout << ans << endl;

  return 0;

}
