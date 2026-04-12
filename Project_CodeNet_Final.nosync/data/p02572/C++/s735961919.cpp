#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P  = pair <int, int>;

#define rep(i, n)     for (int i = 0; i < (int) (n); i++)
#define repr(i, a, b) for (int i = a; i < b; i++)
#define each(i, mp)   for (auto &i : mp)

const int INF = 1001001001;
const ll MOD = 1000000007;
int main()
{
  int n;
  cin >> n;
  vector <ll> a(n);
  rep(i, n) cin >> a[i];

  ll ans = 0;
  // for (int i = 0; i < a.size() - 1; i++) {
  //   for (int j = i + 1; j < a.size(); j++) {
  //     ans += a[i] * a[j];
  //     ans %= MOD;
  //   }
  // }
  // vector <int> s(n + 1, 0); // s[0] = 0 になる
  // string s[n + 1];
  // for (int i = 0; i < n; ++i) { s[i + 1] =  atoi(s[i].c_str()) + atoi(a[i]); }
  // // reverse(s.begin(), s.end());
  // for (int i = 0; i < a.size() - 1; i++) {
  //   ans += a[i] * (stoi(s[n]) - stoi(s[i + 1]));
  //   ans %= MOD;
  // }

  vector <ll> s(n + 1, 0); // s[0] = 0 になる
  vector <ll> tmp(n);
  rep(i, n) tmp[i] = a[i];
  reverse(tmp.begin(), tmp.end());
  for (int i = 0; i < n; ++i) { s[i + 1] = (s[i] + (tmp[i] % MOD)) % MOD; }
  // for (int i = 0; i < n; ++i) { s[i + 1] = (s[i] + (a[i] % MOD)) % MOD; }
  for (int i = 0; i < n - 1; i++) {
    // ans += (a[i] % MOD) * (s[n] - s[i + 1]);
    ans += (a[i] % MOD) * (s[n - (i + 1)]);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}
