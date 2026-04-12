#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll n, x, m;
  cin >> n >> x >> m;

  vector<ll> seenPos(m, -1);
  vector<ll> sum(m + 10, 0);
  ll cur = x, ans;
  seenPos[x] = 1;
  sum[1] = x;

  if (n == 1) {
    cout << x << endl;
    return 0;
  }

  FOR(i, 2, n + 1) {
    cur = (cur * cur) % m;
    if (i == n) {
      cout << sum[n - 1] + cur << endl;
      return 0;
    }
    if (seenPos[cur] == -1) {
      seenPos[cur] = i;
      sum[i] = sum[i - 1] + cur;
      continue;
    }
    sum[i] = sum[i - 1] + cur;
    // seenPos[cur]+1, ..., i でひとかたまり
    ll syuki = i - seenPos[cur];
    ll syukibun = sum[i] - sum[seenPos[cur]];
    ll rem = n - i;
    ll amariCnt = rem - syuki * (rem / syuki);
    ll amari = sum[seenPos[cur] + amariCnt] - sum[seenPos[cur]];
    // DUMP(syuki);
    // DUMP(syukibun);
    // DUMP(rem);
    // DUMP(amariCnt);
    // DUMP(amari);
    ans = sum[i] + syukibun * (rem / syuki) + amari;
    cout << ans << endl;
    break;
  }
}