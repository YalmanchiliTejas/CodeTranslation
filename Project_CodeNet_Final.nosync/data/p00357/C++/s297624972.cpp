#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < (n); i++)
#define mod (ll)(1e9+7)
#define int ll
#define INF 100000000

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

ll n, d[300001] = {0};

bool check() {
  ll a = d[0];
  FOR(i, 1, n) {
    if (a < i * 10) return false;
    if (a < i * 10 + d[i]) a = i * 10 + d[i];
  }
  return true;
}

signed main() {
  cin >> n;
  rep(i, n) {
    cin >> d[i];
  }
  if (check()) {
    reverse(d, d + n);
    if (check()) {
      cout << "yes" << endl;
      return 0;
    } 
  }
  cout << "no" << endl;
	return 0;
}
