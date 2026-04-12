#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)  for(int i=(a),i##formax=(b);i< i##formax;i++)
#define FORR(i,a,b) for(int i=(a),i##formin=(b);i>=i##formin;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x=max((x),(y))
#define mins(x,y) x=min((x),(y))
#define show(x) cout<<#x<<" = "<<(x)<<endl;
#define all(a) ((a).begin()),((a).end())
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define bit(n) (1LL<<(n))
typedef long long ll;
typedef __int128_t lll;
template<class T>using V=vector<T>;
template<class T>using VV=V<V<T>>;
template<class T,class Y>using P=pair<T,Y>;
template<class T,class Y>ostream& operator<<(ostream&o,P<T,Y>&p){return o<<"("<<p.fi<<","<<p.se<<")";}
template<class T>ostream& operator<<(ostream&o,V<T>&v){for(T&t:v)o<<t<<",";return o;}
template<class T>void uniq(V<T>&v){sort(all(v));v.erase(unique(all(v)), v.end());}

lll gcd(lll a,lll b,lll&x,lll&y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll modInv(ll a,ll m){lll x,y;gcd(a,m,x,y);return(x%m+m)%m;}
ll modPow(lll a,lll n,ll m){lll p=1;for(;n;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return p;}
//V<ll>Fac,Rac;void setF(int n,int mod){Fac=Rac=V<ll>(++n);Fac[0]=1;FOR(i,1,n)Fac[i]=Fac[i-1]*i%mod;Rac[n-1]=modInv(Fac[n-1],mod);FORR(i,n-1,1)Rac[i-1]=Rac[i]*i%mod;}
//ll comb(int a,int b,int m){return a<b||b<0?0:Fac[a]*Rac[b]%m*Rac[a-b]%m;}

const int IINF = 1e9+6;
const ll LINF = 1e18;
const int MOD = 1e9+7; //998244353;
const int N = 1e5;
struct UnionFind{
  vector<int> p;
  void init(int n){
    p.assign(n, -1);
  }
  int find(int a){
    return p[a] < 0 ? a : p[a] = find(p[a]);
  }
  void merge(int a, int b){
    p[a] = b;
  }
} uf;
struct LCA{
  int ln;
  vector<vector<int>> p;
  vector<int> d;
  int root(int a, int b){
    if(d[a] > d[b]) swap(a, b);
    int s = d[b] - d[a];
    for(int i=0; i<ln; i++) if((1<<i)&s) b = p[i][b];
    if(a==b) return a;
    for(int i=ln-1; i>=0; i--) if(p[i][a] != p[i][b]) a = p[i][a], b = p[i][b];
    return p[0][a];
  }
  void build(const vector<vector<int>>&G, int r){
    int n = G.size();
    for(ln=1; (1<<ln)<n; ln++);
    p.assign(ln, vector<int>(n));
    d.resize(n);
    function<void (int, int, int)> dfs = [&](int a, int z, int f){
      p[0][a] = z;
      d[a] = f;
      for(int b:G[a]) if(z!=b) dfs(b, a, f+1);
    };
    dfs(r, r, 0);
    for(int i=1; i<ln; i++)for(int j=0; j<n; j++) p[i][j] = p[i-1][p[i-1][j]];
  }
} lca;

int n, m, q;
V<P<int, P<int, int>>> v;
VV<int> e;
V<int> d;
main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  uf.init(n*2-1);
  FOR(_, 0, m){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    v.eb(c, mp(a, b));
  }
  e.assign(n*2-1, V<int>());
  sort(all(v));
  int c = n;
  ll ans = 0;
  for(auto p:v){
    int a = uf.find(p.se.fi);
    int b = uf.find(p.se.se);
    if(a!=b){
      uf.merge(a, c);
      uf.merge(b, c);
      e[c].pb(a);
      e[c].pb(b);
      d.pb(p.fi);
      ans += p.fi;
      c++;
    }
  }
  lca.build(e, n*2-2);
  cin >> q;
  FOR(_, 0, q){
    int s, t;
    cin >> s >> t;
    s--; t--;
    int r = lca.root(s, t);
    cout << ans-d[r-n] << endl;
  }
}