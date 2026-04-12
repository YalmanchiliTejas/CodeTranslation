#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(j,n) for(int j = 0; j < (n); ++j)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define drep2(j,n) for(int j = (n)-1; j >= 0; --j)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define srep2(j,s,t) for (int j = s; j < t; ++j)
#define srep3(k,s,t) for (int k = s; k < t; ++k)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
  
class Combi {
  private:
    v(ll) fac, inv, finv;
   
    void init(ll N) {
      fac[0] = fac[1] = 1; inv[1] = 1; finv[0] = finv[1] = 1;
   
      for (ll i = 2; i < N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
      }
    }
   
  public:
    Combi(ll N) : fac(N + 1), inv(N + 1), finv(N + 1) { init(N + 1); }
   
    int Cmod(ll n, ll k) {
      if (n < k) return 0;
      if (n < 0 || k < 0) return 0;
      return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
   
    ll Pmod(ll n, ll k) {
      if (n < k) return 0;
      if (n < 0 || k < 0) return 0;
      return fac[n] * finv[n - k] % MOD;
    }
  };

int main() {
  ll N,M,K;
  cin >> N >> M >> K;
  Combi c(N*M+3);
  ll x = c.Cmod(N*M-2,K-2);
  ll ans = 0;
  rep(i,M) {
    ans += (ll)(N * N) * (ll)((M-i) * i);
    ans %= MOD;
  }
  rep(i,N) {
    ans += (ll)(M * M) * (ll)((N-i) *i);
    ans %= MOD;
  }
  ans *= x;
  ans %= MOD;
  cout << ans << endl;
  return 0;
}