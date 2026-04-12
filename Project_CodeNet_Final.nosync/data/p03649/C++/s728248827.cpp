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

const int MAX_N = 50;
ll n;
ll a[MAX_N];


int main()
{
  cin >> n;
  forn(i,n) cin >> a[i];

  ll c = 0;
  while (any_of(a,a+n,[](ll v) { return v >= n; })) {
    ll total = accumulate(a,a+n,0LL,[](ll a, ll b) { return a+b/n; });
    forn(i,n) {
      a[i] += (total-a[i]/n) - (a[i]/n)*n;
    }
    c += total;
  }

  cout << c << endl;

  return 0;
}
