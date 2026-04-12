#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forn1(i,n) for (int i = 1; i <= int(n); i++)
#define popcnt __builtin_popcount
#define ffs __builtin_ffs

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
template <typename T> using vec = vector<T>;
typedef vec<int> vi;
typedef vec<ll> vl;


template <typename T> T id(T b) {return b;};
template <class It> bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It> bool any(It f,It l){return std::any_of(f,l,id<bool>);}
template <typename T> void chmax(T &x, T y) {if (x < y) x = y;}
template <typename T> void chmin(T &x, T y) {if (x > y) x = y;}
void fastio() { ios_base::sync_with_stdio(false); cin.tie(nullptr); }
constexpr ll TEN(int n) { if (n == 0) return 1LL; else return 10LL*TEN(n-1); }

const ll MAX_A = TEN(16)+1000;
const int MAX_N = 50;
ll n;
ll a[MAX_N];

ll count(ll m) {
  ll c = 0;
  forn(i,n) {
    c += max((a[i]-m)/(n+1), 0LL);
  }
  return c;
}


int main()
{
  cin >> n;
  forn(i,n) cin >> a[i];

  ll x = max(accumulate(a,a+n,0LL) - n*(n-1), 0LL);

  forn(i,n) a[i] += x;

  ll l = -1, r = MAX_A;
  while (r - l > 1) {
    ll m = (l + r) / 2;
    ll c = count(m);
    if (c <= x)
      r = m;
    else
      l = m;
  }

  ll ans = 0;
  forn(i,n) {
    ll c = max((a[i]-r)/(n+1), 0LL);
    ans += c;
    a[i] -= c*(n+1);
  }

  //cout << ans << ", " << x << endl;

  while (ans < x) {
    auto it = max_element(a,a+n);
    *it -= n+1;
    ans++;
  }

  auto it = max_element(a,a+n);
  while (*it >= n) {
    int idx = it-a;
    forn(i,n) {
      if (i == idx) a[i] -= n;
      else a[i]++;
    }
    it = max_element(a,a+n);
    ans++;
  }

  cout << ans << endl;

  return 0;
}
