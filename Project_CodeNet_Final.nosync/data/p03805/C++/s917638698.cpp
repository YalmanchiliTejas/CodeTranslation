#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef int ll;
typedef pair<ll, ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return b/gcd(a,b)*b;}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> g(n, vector<ll>(n, 0));
  rep(i, m) {
    int from, to;
    cin >> from >> to;
    g[from-1][to-1] = 1;
    g[to-1][from-1] = 1;
  }
  vector<ll> v(n-1);
  rep(i, n-1) {
    v[i] = i+1;
  }
  ll ans = 0;
  do {
    bool ok = true;
    if (!g[0][v[0]]) {
      ok= false;
      continue;
    }
    rep(i, v.size()-1) {
      //printf("g[%d][%d] = %d\n", v[i+1], v[i], g[v[i+1]][v[i]]);
      if (g[v[i+1]][v[i]]==0) {
        ok = false;
        break;
      }
    }
    if (ok) ans++;
  } while(next_permutation(v.begin(), v.end()));//順列全探索
  cout << ans << endl;
  return 0;
}