#include <bits/stdc++.h>
#define pb push_back
#define REP(i, n) for (signed long long i = 0; i < (n); i++)
#define MOD 998244353
#define INF 93193111451418101
#define bitcnt(a) (ll) __builtin_popcount((a))
#define lb(a, b) lower_bound((a).begin(), (a).end(), (b))
#define ub(a, b) upper_bound((a).begin(), (a).end(), (b))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

bool vis[314514] = {};
ll n;
vector<ll> d;

bool DP(ll nowPos) {
  if (nowPos >= n - 1) {
    return true;
  }
  vis[nowPos] = 1;
  bool cnt = 0;
  for (int i = min(d[nowPos] / 10, n - 1 - nowPos); i >= 1; i--) {

    if (vis[nowPos + i] == false)
      cnt |= DP(nowPos + i);
    else {
      break;
    }
  }
  return cnt;
}

int main() {
  cin >> n;
  REP(i, n) {
    ll a;
    cin >> a;
    d.pb(a);
  }
  if (DP(0) == false) {
    return !printf("no\n");
  }
  REP(i, n + 1) { vis[i] = 0; }
  REP(i, n / 2) { swap(d[i], d[n - 1 - i]); }
  if (DP(0) == false) {
    cout << "no" << endl;
  } else {
    cout << "yes" << endl;
  }
}

