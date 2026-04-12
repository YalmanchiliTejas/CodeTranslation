// Author: ElProfesor._.

#include<bits/stdc++.h>

using namespace std;
 
// Competetive Template:
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ldb;
typedef pair <ll,ll> pll;
typedef pair <ll,string> pls;
typedef pair <string, ll> psl;

typedef vector <ll> vl;
typedef vector <pll> vll;
typedef vector <string> vs;
typedef vector <char> vc;

typedef set <ll> sl;
typedef set <pll> sll;
typedef set <char> sc;

typedef map <ll, ll> mll;
typedef map <pll, ll> mpll;
typedef map <string, ll> msl;

typedef priority_queue <ll> max_heap ;
typedef priority_queue < ll, vector<ll> , greater<ll> > min_heap;

// Debugging :
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
 
#define pb push_back 
#define pf push_front
#define in insert 
#define popb pop_back
#define popf pop_front
#define ba  back
#define si size()
#define be begin()
#define en end()
#define le length()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair 
#define mt make_tuple
#define fi first
#define se second
#define deb debug
#define all(v) v.be, v.en
#define INF LLONG_MAX
const ldb PI = acos(-1.0);

#define forz(i, n) for (int i = 0; i < n; i++)
#define rforz(i, n) for (int i = n - 1; i >= 0; i--)

#define fore(i, m, n) for (int i = m; i <= n; i++)
#define rfore(i, m, n) for (int i = n; i >= m; i--)

#define deci(n)  fixed<<setprecision(n)
#define high(n) __builtin_popcount(n)
#define parity(n) __builtin_parity(n)
#define ctz(n)  __builtin_ctz(n)
#define mod 1000000007
#define mod2 998244353
#define EPSILON 1e-9

// I/O from a file.
#define file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

// Printing Data :
#define pvec(v) forz(i,v.si) cout<<v[i]<<" "; cout<<"\n";
#define parr(arr, n) forz(i,n) cout<<arr[i]<<" "; cout<<"\n";

#define p1(i) cout<<i<<"\n"
#define p2(i, j) cout<<i<<" "<<j<<"\n"
#define p3(i, j, k) cout<<i<<" "<<j<<" "<<k<<"\n"
#define p4(i, j, k, l) cout<<i<<" "<<j<<" "<<k<<" "<<l<<"\n"

// Exponentiation in O(log y)
ll power(ll x,ll y){ll res=1; x=x;while(y>0){if(y&1) res=(res*x);y=y>>1;x=(x*x);}return res;} 

// Modular Exponentiation in O(log y)
ll power(ll x,ll y,ll p){ll res=1; x=x%p;while(y>0){if(y&1) res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;} 

// Euclidean gcd
ll gcd(ll a, ll b) { if (a==0) return b; return gcd(b % a, a);}

// Returns ceil(a/b)
ll ceil2(ll a, ll b) {ll c=a/b; if(a%b)c++;return c;}

// CODE BEGINS :
void solve()
{
	ll n; cin>>n;
	cout << (n>=30 ? "Yes" : "No") << endl; 
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0),cout.tie(0);

    ll t=1; 
    // cin>>t;

    while(t--)
    {
        solve();
    }
    
    return 0;
}

























































