#include <bits/stdc++.h>

using namespace std;

#ifdef ACMTUYO
struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#else
struct RTC{};
#define DBG(X)
#endif

#define fast_io() ios_base::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int ll;
const int maxn = 200010;
const ll mod = 1000000007LL;
int main() {
  int n;
  scanf("%d", &n);
  ll sum = 0, ans = 0;
  forn (i, n) {
    ll x;
    scanf("%lld", &x);
    ans = (ans + sum * x) % mod;
    sum = (sum + x) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
