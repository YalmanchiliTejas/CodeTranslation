#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

using namespace std;
#define ll  long long
#define PI  acos(-1)
#define pb  push_back
#define ins insert
#define INF 5000000000000000007 //1e18+7
#define mk  make_pair
#define ff  first
#define ss  second
#define endl "\n"
#define max3(x,y,z)  max(x,max(y,z))
#define min3(x,y,z)  min(x,min(y,z))
#define sz(a) (ll)a.size()
#define double long double
#define coud(a,b) cout << fixed << setprecision((b)) << (a)
#define mset(x,y)  memset(x,y,sizeof(x))
#define all(x)   (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define bp(n)  __builtin_popcountll(n)
#define mxt(a)  *(max_element(a.begin(),a.end()))
#define mnt(a)  *(min_element(a.begin(),a.end()))
#define unique_sort(c) (sort(all(c)), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define trav(a, x)    for(auto &a : x)

const double eps=1e-7;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int d8x[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int d8y[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int d4x[4]={1, 0, 0, -1};
int d4y[4]={0, -1, 1, 0};
ll power(ll x,ll y){ll ans=1;x=x;while(y>0){if(y&1)ans=(ans*x);y=y>>1;x=(x*x);}return ans;}
ll sqr(ll x) { return x * x;}

template <typename T> T gcd(T a,T b){ if(a==0) return b; return gcd(b%a,a); }
template <class T> inline void chmax(T &x,T y){ x = max((x), (y));}
template <class T> inline void chmin(T &x,T y){ x = min((x), (y));}
template <class T> T abs(T x) { return x>0 ? x : -x;}
template <typename T> T powm(T a,T b, ll m){T cnt=1; while(b>0) { if(b%2==1) cnt=(cnt*a)%m; b/=2; a=(a*a)%m; }return cnt%m;}
typedef pair<int,int>  pii;
typedef pair<ll,ll>  pll;
typedef vector<pll>  vpll;
typedef vector<pii>  vpii;
typedef vector<ll>   vll;
typedef vector<int>  vii;
#define minpq priority_queue<T,vector<T>,greater<T> >;
// #define T int
// #define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
//*X.find_by_order(k) returns the kth largest element (0-based).
//X.order_of_key(val) returns the no. of values less than val.
ll ncr(ll n,ll r) {ll ans=1;if(r>n)return 0;if(r>n-r)r=n-r;for(ll i=0;i<r;i++){ans*=(n-i);ans/=(i+1);}return ans;}
const int MOD = 1000000007;   
const int N = 200100;

// 🎲
ll n, a[N], pre[N], ans;
int32_t main() {
  cin.sync_with_stdio(0);cin.tie(0);
  cin.exceptions(cin.failbit);
  
  cin >> n;
  rep(i,1,n) cin >> a[i];
  rep(i,1,n) pre[i] = pre[i-1] + a[i], pre[i] %= MOD;
  for (int i=1; i<n; ++i) {
    ans = ans%MOD + ((a[i]%MOD)*(pre[n] - pre[i] + MOD)%MOD)%MOD;
    ans %= MOD;
  }
  cout << ans;
  return 0; 
}

/* 
    stuff you shoulds look for
    * int overflow,array bounds.
    * special cases (n=1?).
    * N,MOD value.
*/