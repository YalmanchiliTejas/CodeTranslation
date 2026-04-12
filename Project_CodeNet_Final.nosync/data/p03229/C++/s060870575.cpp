#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
template <class T> void chmin(T &a, const T &b) noexcept { if (b < a) a = b; }
template <class T> void chmax(T &a, const T &b) noexcept { if (a < b) a = b; }
void print() { cout << "\n"; }
template <class T, class... Args>
void print(const T &x, const Args &... args) { cout << x << " "; print(args...);}
void debug_out() { cout << "\n"; }
template <class T, class... Args>
void debug_out(const T &x, const Args &... args) { cout << x << " "; debug_out(args...);}
#ifdef _DEBUG
  #define debug(...) debug_out(__VA_ARGS__)
#else
  #define debug(...) 
#endif

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(all(a));
  ll ans = 0;
  if (n % 2 == 0) {
    for (int i = 0; i < n/2; ++i) {
      if (i == n/2 - 1) ans -= a[i];
      else ans -= 2*a[i];
    }
    for (int i = n-1; i >= n/2; --i) {
      if (i == n/2) ans += a[i];
      else ans += 2*a[i];
    }
  }
  else {
    for (int i = 0; i < n/2+1; ++i) { //方法1
      if (i == n/2-1 || i == n/2) ans -= a[i];
      else ans -= 2*a[i];
    }
    for (int i = n/2+1; i < n; ++i) {
      ans += 2*a[i];
    }
    ll temp = 0;
    for (int i = 0; i < n/2; ++i) { //方法2
      temp -= 2*a[i];
    }
    for (int i = n/2; i < n; ++i) {
      if (i == n/2 || i == n/2+1) temp += a[i];
      else temp += 2*a[i];
    }
    chmax(ans,temp);
  }
  cout << ans << endl;
  return 0;
}