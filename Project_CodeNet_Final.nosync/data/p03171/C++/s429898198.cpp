//It gets easier day by day, but the hard part is to........
// "I am here." ~ All Might!
#pragma optimise GCC(-O2)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll int
#define ld long double
#define pii pair<ll,ll>
#define ve(x) vector<x>
#define f(a,b,c) for(ll a=b;a<c;a++)
#define foto(x,v) for(auto x:v)
#define read(t) ll t; cin>>t;
#define reads(t) string t; cin>>t;
#define readarr(arr,n) ll arr[n]; f(i,0,n) cin>>arr[i];
#define ln endl
#define Endl endl
#define dbg(x) cout<<#x<<" = "<<x<<ln;
#define dbg2(x,y) cout<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<ln;
#define dbgarr(v,s,e) cout<<#v<<" = "; f(i,s,e) cout<<v[i]<<", "; cout<<ln;
#define addEdge(tr,k) f(i,0,k) { ll x,y; cin>>x>>y, tr[x].push_back(y);}
#define all(v) v.begin(),v.end()

mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) { uniform_int_distribution<int> uid(0, lim - 1); return uid(rang); }

//														GLOBAL VARS
ll INF =LLONG_MAX;
const ll M= 1000000007, M2 = 998244353 , M3 = 2013265921;

//														USEFUL FUNCTIONS
ll powm(ll ,ll , ll);
ll modI(ll , ll ) ;

//------------------------------------------------------DSU 
// vector<int> parent, rank;
// void make_set(int v) { parent[v] = v; rank[v] = 0;}
// int find_set(int v) { if (v == parent[v]) return v; return parent[v] = find_set(parent[v]);}
// void union_sets(int a, int b) { a = find_set(a);  b = find_set(b); if (a != b) { if (rank[a] < rank[b]) swap(a, b); parent[b] = a; if (rank[a] == rank[b]) rank[a]++; }}

//------------------------------------------------------LCA  ** l=ceil(log2(n)) dfs_lca(root,root)
// ll dp[200005][21] ; ve(ll) tin(200005), tout(200005); ll tim = 0 , l;
// void dfs_lca(int n , int par ){  tin[n] = ++tim; dp[n][0] = par; f(i,1,l+1) dp[n][i] = dp[dp[n][i-1]][i-1];
//    foto(x,tr[n]) if(x==par) continue; else dfs_lca(x , n);        tout[n] = ++tim;  }
// bool is_ancestor(ll u , ll v) { return tin[u]<=tin[v] && tout[u]>=tout[v] ;}
// ll lca(ll u , ll v){ if(is_ancestor(u,v)) return u ; if(is_ancestor(v,u)) return v;
//    for(int j = l ; j>=0 ; j--) if(!is_ancestor(dp[u][j] , v)) u = dp[u][j];    return dp[u][0];}

struct FenwickTree { vector<int> bit; int n; FenwickTree(int n){this->n = n;bit.assign(n, 0);}
int sum(int r) { int ret = 0; for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r]; return ret;}
int sum(int l, int r) { return sum(r) - sum(l - 1); }
void add(int idx, int delta) { for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta; }};

//-------------------------------------------------NTT modulo m primroot x=(m,0)-------------------- //
ll PrimRoot(ll p,ll x); //finds primitive root of prime p greater than x(If it doesnt exist, returns 0)
void fft(ve(ll) &a,ll n,bool invert,ll m,ll x);
void PolyMult(ve(ll) &a,ve(ll) &b,ve(ll) &v,ll m,ll x);
ll dp[3005][3005];
ll go(ll a[] , ll i , ll j , bool foo )
{
  if(i>j) return 0;
  if(dp[i][j] != -1) return dp[i][j];
  ll ans = 0 ;
  if(foo) ans = max(a[i]+go(a,i+1,j,!foo) , a[j]+go(a,i,j-1,!foo));
  if(!foo) ans = min(-a[i]+go(a,i+1,j,!foo) , -a[j]+go(a,i,j-1,!foo));
  return dp[i][j] = ans;
}

// 														MAIN
int32_t main()
{ 
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	cout.tie(NULL);
  read(n) 
  readarr(a,n)
  f(i,0,3005) f(j,0,3005) dp[i][j] = -1;
  cout<<go(a , 0 , n-1 , 1);
}

//   ---------------  Oooo I wont let you go  --------------
// lcs(i , j) = (s[i]==t[j]) ? lcs(i-1,j-1) + 1 : max(lcs(i-1,j),lcs(i,j-1)) ;

//													FUNCTIONS DECLARATIONS
ll powm(ll a, ll b , ll c = M) { ll res=1; while(b) { if(b&1) res=(res*a)%c; a=(a*a)%c; b>>=1; } return res;}

ll modI(ll a, ll m = M)
{ ll m0=m,y=0,x=1;if(m==1) return 0; while(a>1) { ll q=a/m; ll t=m; m=a%m; a=t; t=y; y=x-q*y;  x=t; }
  if(x<0) x+=m0; return x; }

ll PrimRoot(ll p,ll x) //finds primitive root of prime p greater than x(If it doesnt exist, returns 0)
{ ve(ll) v; ll t=p-1; for(int i=2;i*i<=t;i++) if(t%i==0){v.push_back((p-1)/i); while(t%i==0) t/=i; } if(t>1)v.push_back((p-1)/t);
  f(i,x+1,p){ ll flag=0; foto(x,v) if(powm(i,x,p)==1) { flag=1;break; }if(flag==0) return i; } return 0; }

void fft(ve(ll) &a,ll n,bool invert,ll m,ll x)
{ ll lg_n = __builtin_ctzll(n);
  for(ll i=0, y=0 ;i<n ; i++)
  { f(j,0,lg_n)   if((1LL<<j)&i)  y|=(1LL<<(lg_n-j-1)); if(y>i) swap(a[i],a[y]); }
  if(invert) x=modI(x,m);
  for(ll s = 2 ; s<=n ; s<<=1)
  { ll y=powm(x,(n/s),m); f(j,0,(n/s)) { ll r=1; f(i,0,s/2)
  { ll u=a[i+j*s] , v=(r*a[i+j*s+(s/2)])%m; a[i+j*s]=(u+v) %m; a[i+j*s+(s/2)]=(u-v+m)%m; r = r*y % m;} } }
  if(invert){ll invn=modI(n,m); f(i,0,n) a[i]=(a[i]*invn)%m; } return; }

void PolyMult(ve(ll) &a,ve(ll) &b,ve(ll) &v,ll m,ll x) // pass x = 1 for xor conv
{ ll n=1;while(n<((ll)a.size())+((ll)b.size())) n<<=1;
  ve(ll) fa(a.begin(),a.end()); fa.resize(n,0);
  ve(ll) fb(b.begin(),b.end()); fb.resize(n,0);
  ll y=powm(x,(m-1)/n,m); fft(fa,n,false,m,y); fft(fb,n,false,m,y); v.resize(n,0);
  f(i,0,n) v[i]=((fa[i]*fb[i])%m); fft(v,n,true,m,y); return; }

