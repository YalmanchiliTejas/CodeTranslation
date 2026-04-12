#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) { cout << H << " "; debug_out(T...); }
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  ll n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << n * n << endl;
    return 0;
  }
  ll ans = 0;
  for (ll b = k+1; b <= n; ++b) {
    ll num = n / b;
    ans += (b-k) * num;
    ans += max((n % b) - k+1, 0LL);
    debug(b, (b-k) * num, (n % b) - k+1, ans);
  }
  cout << ans << endl;
  return 0;
}