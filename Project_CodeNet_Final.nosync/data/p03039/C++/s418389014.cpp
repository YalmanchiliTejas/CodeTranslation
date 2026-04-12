#include <bits/stdc++.h>

#define mp make_pair
#define fst first
#define snd second
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forn1(i,n) for (int i = 1; i <= int(n); i++)
#define popcnt __builtin_popcount

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template <typename T> T id(T b) {return b;};
template <class It> bool all(It f,It l){return std::all_of(f,l,id<bool>);}
template <class It> bool any(It f,It l){return std::any_of(f,l,id<bool>);}
template <typename T> void chmax(T &x, T y) {if (x < y) x = y;}
template <typename T> void chmin(T &x, T y) {if (x > y) x = y;}

const long long MOD = 1000000007;

long long mod_pow(long long a, long long b)
{
  if (b == 0) return 1;
  long long ret = mod_pow(a, b/2);
  ret = ret * ret % MOD;
  if (b % 2 == 1) ret = a * ret % MOD;
  return ret;
}

long long comb(long long a, long long b)
{
  if (b > a - b) return comb(a, a - b);

  long long num = 1;
  long long denom = 1;

  for (int i = 1; i <= b; i++) {
    num = num * (a - i + 1) % MOD;
    denom = denom * i % MOD;
  }

  return num * mod_pow(denom, MOD-2) % MOD;
}

ll calc(ll n, ll m, ll k) {
  ll c = comb((n*m-2+MOD)%MOD,k-2);
  ll res = 0;
  for (int d = 1; d < n; d++) {
    res = (res + d*(n-d)*m%MOD*m*c%MOD) % MOD;
  }
  return res;
}

ll n,m,k;

int main()
{
#ifdef FASTIO
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
#endif

  cin >> n >> m >> k;

  ll res = (calc(n,m,k) + calc(m,n,k)) % MOD;

  cout << res << endl;

  return 0;
}
