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
	ll w, l, d, n;
  string name;
  bool ch = false;
  while(cin >> n, n) {
    vector<pair<int, string> > result;
    if(ch) cout << endl;
    rep(i, n) {
      cin >> name >> w >> l >> d;
      ll pt = (3 * w + d) * 100 + 99 - i;
      result.pb(make_pair(pt, name));
    }
    sort(result.begin(), result.end());
    reverse(result.begin(), result.end());
    rep(i, n) {
      cout << result[i].second << "," << result[i].first / 100 << endl;
    }
    ch = true;
  }
	return 0;
}
