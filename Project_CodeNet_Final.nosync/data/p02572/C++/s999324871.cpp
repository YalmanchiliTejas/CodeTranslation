#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define l_l pair<ll, ll>
#define vll vector<ll>
#define mll map<ll, ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

class Cumu {
 private:
  vector<ll> _sum;

 public:
  Cumu(vector<ll> &source) {
    _sum = vector<ll>(source.size() + 1);
    for (ll i = 1; i < source.size() + 1; i++) {
      _sum[i] = _sum[i - 1] + source[i - 1];
    }
  }
  ll sum(ll left, ll right) {
    //
    return _sum[right + 1] - _sum[left];
  }
};

int main() {
  ll N;
  scanf("%lld", &N);

  vector<ll> list;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    list.emplace_back(v);
  }

  auto cumu = Cumu(list);

  ll ans = 0;

  for (ll i = 0; i < N - 1; i++) {
    ll plus = (list[i] * (cumu.sum(i + 1, N - 1) % MOD)) % MOD;
    ans += plus;
    ans %= MOD;
  }
  cout << ans << endl;
}
