#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x=max(x,y)
#define mins(x,y) x=min(x,y)
#define show(x) cout<<#x<<" = "<<x<<endl;
#define all(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define perm(c) sort(all(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))
#define bit(n) (1LL<<(n))
#define randInt(l,r) (uniform_int_distribution<ll>(l,r)(rnd))
#define randDouble(l,r) (uniform_real_distribution<double>(l,r)(rnd))

typedef long long ll;
typedef __int128_t lll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T>using V=vector<T>;
template<class T>using VV=V<V<T>>;
template<class T,class Y>ostream& operator<<(ostream& o,const pair<T,Y>& p){return o<<"("<<p.fi<<", "<<p.se<<")";}
template<typename A,size_t N,typename T>void Fill(A (&array)[N],const T&v){fill((T*)array,(T*)(array+N),v);}
lll gcd(lll a,lll b,lll &x,lll &y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll gcd(ll a,ll b){lll x=0,y=0;return gcd(a,b,x,y);}
ll modPow(lll a,lll n,ll m){if(!a)return a;lll p=1;for(;n>0;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return(ll)p;}
bool isPrime(ll n){if(n<2||n%2==0)return n==2;lll t=n-1,d=t/(t&-t);for(lll a:{2,325,9375,28178,450775,9780504,1795265022})if(a%n){for(t=d,a=modPow(a,t,n);t!=n-1&&a!=1&&a!=n-1;a=a*a%n,t=t*2%n);if(a!=n-1&&t%2==0)return 0;}return 1;}
void dout(double d){printf("%.12f\n",d);}
const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7;
const double PI = acos(-1);
const double EPS = 1e-10;
static random_device rd;
static mt19937 rnd(rd());

const int N = 1e5;
struct Dijk{
  typedef long long ll;
  const ll tinf = 1e18;
  int n;
  vector<ll> d, c;
  vector<int> p;
  void solve(const vector<vector<pair<int, ll>>>&E, int S, int G=-1){
    n = E.size();
    d = vector<ll>(n, tinf);
    c = vector<ll>(n, 0);
    p = vector<int>(n, -1);
    d[S] = 0;
    c[S] = 1;
    priority_queue<pair<ll, int>,vector<pair<ll, int>>,greater<pair<ll, int>>> Q;
    Q.push(pair<ll, int>(0, S));
    while(!Q.empty()){
      pair<ll, int> t=Q.top(); Q.pop();
      c[t.second] %= MOD;
      if(t.second == G) return;
      if(t.first > d[t.second]) continue;
      for(auto itr = E[t.second].begin(); itr != E[t.second].end(); itr++){
        ll k = t.first + itr->second;
        int m = itr->first;
        if(k < d[itr->first]){
          d[m] = k;
          p[m] = t.second;
          c[m] = 0;
          Q.push(pair<ll, int>(k, m));
        }
        if(k == d[itr->first]) c[m] += c[t.second];
      }
    }
  }
} ds, dt;
VV<pair<int, ll>> E;
int n, m, s, t;
ll a, b;
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m >> s >> t;
  E.resize(n);
  FOR(i, 0, m){
    int u, v;
    ll d;
    cin >> u >> v >> d;
    u--; v--;
    d <<= 1;
    E[u].pb(mp(v, d));
    E[v].pb(mp(u, d));
  }
  s--; t--;
  ds.solve(E, s);
  dt.solve(E, t);
  ll T = ds.d[t] / 2;
  FOR(i, 0, n) if(ds.d[i]==T && dt.d[i]==T){
    ll c = ds.c[i] * dt.c[i] % MOD;
    a += c;
    b += c * c % MOD;
  }
  FOR(i, 0, n) each(itr, E[i]) if(ds.d[i]<T && dt.d[itr->fi]<T && T*2==ds.d[i]+dt.d[itr->fi]+itr->se){
    ll c = ds.c[i] * dt.c[itr->fi] % MOD;
    a += c;
    b += c * c % MOD;
  }
  a %= MOD;
  b %= MOD;
  cout << (a*a+MOD-b)%MOD << endl;
}