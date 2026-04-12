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

int main() {
  // std::cout << std::fixed << std::setprecision(10);
  ll N;
  scanf("%lld", &N);

  vector<ll> a_list;
  for (ll i = 0; i < N; i++) {
    ll v;
    scanf("%lld", &v);
    a_list.emplace_back(v);
  }

  vector<ll> csum(a_list.size() + 1);
  for (ll i = 1; i < a_list.size() + 1; i++) {
    csum[i] = csum[i - 1] + a_list[i - 1];
  }
  // // [2] + [3] + [4]
  // cout << (csum[4 + 1] - csum[2]) << endl;
  // // [1] + [2] + [3]
  // cout << (csum[3 + 1] - csum[1]) << endl;

  ll ans = 0;

  for (ll i = 0; i < N - 1; i++) {
    ll s = (csum[N - 1 + 1] - csum[i + 1]);
    s %= MOD;
    ll plus = a_list[i] * (s);
    plus %= MOD;
    ans += plus;
    ans %= MOD;
  }

  cout << ans << endl;
}
