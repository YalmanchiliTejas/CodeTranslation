#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); i++)
#define dep(i, a, n) for(int i = a; i >= (n); i--)
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define mod (ll)(1e9+7)
#define int ll
#define INF 100000000

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

signed main() {
	ll h, w;
  bool ch;
  char a[101][101];
  bool b[101][101];
  rep(i, 101) rep(j, 101) b[i][j] = false;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> a[i][j];
  rep(i, h) {
    ch = false;
    rep(j, w) {
      if(a[i][j] == '#') ch = true;
    }
    if(ch) continue;
    rep(j, w) b[i][j] = true;
  }
  rep(j, w) {
    ch = false;
    rep(i, h) {
      if(a[i][j] == '#') ch = true;
    }
    if(ch) continue;
    rep(i, h) b[i][j] = true;
  }
  bool cc = false;
  rep(i, h) {
    ch = false;
    rep(j, w) {
      if(!b[i][j]) {
        ch = true;
        break;
      }
    }
    if(cc && ch) cout << endl;
    rep(j, w) {
      if(!b[i][j]) {
        cout << a[i][j];
        cc = true;
      }
    }
  }
  cout << endl;
	return 0;
}