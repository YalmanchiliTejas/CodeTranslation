#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, X, M;
  cin >> N >> X >> M;
  if (M == 0) {
    cout << X << "\n";
    return 0;
  }
  vector<ll> already(M + 1, -1);
  already.at(X) = 1;
  ll cnt = 1;
  ll len = 0, seg_sum = X;
  ll now = X;
  vector<ll> seg_sums = {0, now};
  while (true) {
    now = (ll)pow(now, 2) % M;
    if (already.at(now) != -1) {
      len = cnt + 1 - already.at(now);
      break;
    }
    already.at(now) = cnt + 1;
    cnt += 1;
    seg_sum += now;
    seg_sums.push_back(seg_sum);
  }
  if (N < cnt) {
    cout << seg_sums.at(N) << "\n";
  }
  else {
    ll ans = seg_sum + (seg_sums.at(seg_sums.size() - 1) - seg_sums.at(max(0ll, (ll)seg_sums.size() - len - 1))) * ((N - cnt) / len) + seg_sums.at(max(0ll, (ll)seg_sums.size() - len - 1 + (N - cnt) % len)) - seg_sums.at(max(0ll, (ll)seg_sums.size() - len - 1));
    cout << ans << "\n";
  }
}
