#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
const ll mod = 1e9+7;
const ll INF = 1e18;
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i,h) cin >> a[i];
  vector<vector<bool>> q(h, vector<bool>(w));

  //横
  rep(i,h) {
    rep(j,w) {
      if (a[i][j] == '#') break;
      if (j == w-1 && a[i][j] == '.') {
        rep(k,w) {
          q[i][k] = true;
        }
      }
    }
  }

  //縦
  rep(i,w) {
    rep(j,h) {
      if (a[j][i] == '#') break;
      if (j == h-1 && a[j][i] == '.') {
        rep(k,h) {
          q[k][i] = true;
        }
      }
    }
  }

  ll c = 0;
  rep(i,h) {
    rep(j,w) {
      if (q[i][j] == false) {
        cout << a[i][j];
        ++c;
      }
    }
    if (c == 0) continue;
    else {
      cout << '\n';
      c = 0;
    }
  }

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}