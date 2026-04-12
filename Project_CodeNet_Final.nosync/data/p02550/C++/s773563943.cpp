#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  ll n;
  int x, m;
  cin >> n >> x >> m;

  vector<vector<ll>> to(40, vector<ll>(m, 0)), sum(40, vector<ll>(m, 0));
  rep(i,m) {
    to[0][i] = (ll)i * i % m;
    sum[0][i] = i;
  }

  for (int i = 0; i < 39; i++) {
    for (int j = 0; j < m; j++) {
      to[i + 1][j] = to[i][to[i][j]];
      sum[i + 1][j] = sum[i][j] + sum[i][to[i][j]];
    }
  }

  int cur = x;
  ll res = 0;
  for (int j = 0; j < 40; j++) {
    if ((n >> j) & 1) {
      res += sum[j][cur];
      cur = to[j][cur];
    }
  }
  cout << res << endl;
  return 0; 
}