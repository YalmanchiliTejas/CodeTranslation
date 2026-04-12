#include <bits/stdc++.h>
#define fi first
#define se second
#define FOR(i,m,n) for(ll i=(m);i<(n);++i)
#define dFOR(i,m,n) for(ll i=(m)-1;i>=(n);--i)
#define rep(i,n) FOR(i,0,(n))
#define drep(i,n) dFOR(i,(n)-1,(0)) // decrease
#define rng(a) (a).begin(),(a).end()
#define rrng(a) (a).rbegin(),(a).rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
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
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vp;
typedef vector<T> vt;
//inline int in() { int x; scanf("%d",&x); return x;}
inline ll in() { ll x; cin >> x; return x; }
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10; //epsilon
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 200005;
#define chmin(x,y) x = min(x,y)

const int MOD = 1000000007;
struct mint {
  ll x;
  mint(ll x=0):x(x%MOD){}
  mint& operator+=(const mint a) { if ((x += a.x) >= MOD) x -= MOD; return *this; }
  mint& operator-=(const mint a) { if ((x += MOD-a.x) >= MOD) x -= MOD; return *this; }
  mint& operator*=(const mint a) { (x *= a.x) %= MOD; return *this; }
  mint operator+(const mint a) const { mint res(*this); return res+=a; }
  mint operator-(const mint a) const { mint res(*this); return res-=a; }
  mint operator*(const mint a) const { mint res(*this); return res*=a; }
  mint operator++() { return *this = mint(x + 1); }
  mint operator--() { return *this = mint(x - 1); }
};

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
map<ll, ll> prime_factor(ll n) {
  map<ll, ll> ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n != 1) ret[n] = 1;
  return ret;
}

const int MAX = 1001001;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
ll nCr(int n, int k){
  if (n < k || n < 0 || k < 0) return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

struct Edge { int to, id;};
vv(Edge) e;
vi cc;
void dfs(int v, int color=-1, int from=-1) {
  int cnt = 1;
  rep(i,e[v].size()) {
    int eid = e[v][i].id;
    if (e[v][i].to == from) continue;
    if (cnt == color) ++cnt;
    cc[eid] = cnt;
    ++cnt;
    dfs(e[v][i].to, cc[eid],v);
  }
}

bool is_prime(ll x){
  for (int i=2; i*i<=x; i++) if(x%i==0) return false;
  return true;
}

/*-------------------------------------------------*/
int main() {
  string s; cin >> s;
  if (s == "AAA" || s == "BBB") cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}
