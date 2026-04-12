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

ll f(ll n, ll x) {
  if (n == 0) return 1;
  ll a = (1LL<<(n+1)) - 3; //a_{n-1}
  ll p = (1LL<<(n)) - 1; //p_{n-1}
  debug(a, p, n, x);
  if (x == 1) return 0;
  else if (x <= a+1) return f(n-1,x-1);
  else if (x == a+2) return p+1;
  else return p + 1 + f(n-1, x-(a+2));
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cout << std::fixed << std::setprecision(15);
  ll n, x;
  cin >> n >> x;
  cout << f(n,x) << endl;
  return 0;
}