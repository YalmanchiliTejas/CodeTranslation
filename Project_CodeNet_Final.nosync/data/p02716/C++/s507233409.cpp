#include <bits/stdc++.h>
using namespace std;
#define rep2(i, m, n) for(int i=int(m); i<int(n); ++i)
#define drep2(i, m, n) for(int i=int(m-1); i>=int(n); --i)
#define rep(i, n) rep2(i, 0, n)
#define drep(i, n) drep2(i, n, 0)
using ll = long long;
using Vll = vector<ll>;
template<typename T> istream &operator>>(istream &is, vector<T> &v) { for (auto &e : v) is >> e; return is; }


int main() {
  ll n; cin >> n;
  Vll a(n); cin >> a;

  ll m = n/2;
  ll k = (n%2) ? 3 : 2;

  Vll dp(k);
  rep(i, m) drep(j, k) dp[j] = *max_element(dp.begin(), dp.begin()+j+1) + a[2*i+j];

  cout << *max_element(dp.begin(), dp.end()) << endl;
  return 0;
}
