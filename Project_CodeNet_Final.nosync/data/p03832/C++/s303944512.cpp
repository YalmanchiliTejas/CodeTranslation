#include "bits/stdc++.h"
using namespace std;

#define FAST ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define eb emplace_back
#define ins insert
#define ph push
#define f first
#define s second
#define cbr cerr << "hi\n"
#define mmst(x, v) memset((x), v, sizeof ((x)))
#define siz(x) ((ll)x.size())
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define btinpct(x) __builtin_popcountll((x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());    //can be used by calling rng() or shuffle(A, A+n, rng)
inline long long rand(long long x, long long y) { return (rng() % (y+1-x)) + x; } //inclusivesss
string to_string(char c) {string s(1,c);return s;} template<typename T> inline T gcd(T a,T b){ return a==0?b:gcd(b%a,a); }

#define ll long long int 
#define ld long double
#define FOR(ii, ss, ee) for(ll ii = (ss); ii <= (ll)(ee); ++ii)
#define DEC(ii, ss, ee) for(ll ii = (ss); ii >= (ll)(ee); --ii)
typedef pair <ll, ll> pi; typedef pair <ll, pi> spi; typedef pair <pi, pi> dpi;

#define LLINF ((long long) 1e18)//1234567890987654321
#define INF 1234567890ll
// #define cerr if(0)cout
#define MAXN (1006)
ll n, a, b, c, d, dp[MAXN][MAXN], f[MAXN]; // groups with i people or less, j people so far
const ll MOD=1e9+7;
ll qexp(ll x,ll e) {
  if(e==0) return 1;
  ll half=qexp(x,e/2);
  half*=half;
  half%=MOD;
  if(e&1) half*=x, half%=MOD;
  return half;
}
unordered_map<int, int> mp;
ll mul_inv(ll x) { if(mp.find(x)!=mp.end()) return mp[x]; return mp[x]=qexp(x,MOD-2); }
ll P(ll n,ll k) { assert(n>=k); 
  return f[n] * mul_inv(f[n-k]) % MOD;
}
int main()
{
  FAST
  cin>>n>>a>>b>>c>>d;
  f[0]=f[1]=1; FOR(i,2,MAXN-1) f[i]=f[i-1]*i%MOD;
  vector<ll> v;
  v.pb(0);
  FOR(i,c,d) v.pb(i);
  FOR(i,0,MAXN-1) dp[i][0]=1;
  FOR(i,a,b) {
    FOR(j,1,n) {
      for(auto k:v) if(j>=i*k) {
        dp[i][j] += dp[i-1][j-i*k] * P(n-(j-i*k), i*k) % MOD * mul_inv(qexp(f[i], k)) % MOD * mul_inv(f[k]) % MOD;
        dp[i][j] %= MOD; 
      } else break;
    }
  } 
  cout<<dp[b][n];
  // cout<<(dp[b][n]-dp[a-1][n]+MOD)%MOD<<'\n';
}