#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int
#define LL_MAX 9223372036854775807
#define pb push_back
#define pf push_front
#define mp make_pair
#define popb pop_back
#define vl vector<ll>
#define bs(v, x) binary_search(v.begin(), v.end(), x)
#define popf pop_front
#define p() cout << '\n'
#define p0(x) cout << x << " "
#define p1(x) cout << x << '\n'
#define p2(x, y) cout << x << " " << y << '\n'
#define p3(x, y, z) cout << x << " " << y << " " << z << '\n'
#define printv(v)                   \
  for (ll i = 0; i < v.size(); ++i) \
    cout << v[i] << " ";            \
  cout << '\n'
#define pr1(x) cout << fixed << setprecision(15) << x << '\n'
#define mod 1000000007
#define mod1 998244353
#define fio                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL)
#define get(n) \
  ll n;        \
  cin >> n
#define getvec(v, n)         \
  vector<ll> v(n);           \
  for (ll i = 0; i < n; i++) \
    cin >> v[i];
#define getstr(s) \
  string s;       \
  cin >> s
#define all(x) x.begin(), x.end()
#define countBits(x) __builtin_popcount(x)
using namespace std;

void mainSolve()
{
  get(n);
  getvec(v, n);
  vl sum(n + 1, 0);
  sum[n - 1] = v[n - 1];
  for (int i = n - 2; i >= 0; i--)
    sum[i] = (sum[i + 1] + v[i]) % mod;
  ll ans = 0;
  for (int i = 0; i < n; i++)
  {
    ll term = (v[i] * (sum[i + 1])) % mod;
    ans = (ans + term) % mod;
  }
  p1(ans);
}

int main()
{
  fio;
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  //get(t);
  ll t = 1;
  while (t--)
  {
    mainSolve();
  }
  return 0;
}
