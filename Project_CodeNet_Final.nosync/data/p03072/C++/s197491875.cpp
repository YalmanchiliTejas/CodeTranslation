/*
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;++i)
#define fre(i,a,b) for(int i=a;i<=b;i++)
#define rpe(i,a,b) for(i=a-1;i>=b;i--)
#define rp(i,n) rep(i,0,n)
#define fr(i,n) fre(i,1,n)
#define trav(a, x) for (auto& a : x)
#define pb push_back
#define eb emblace_back
#define mp make_pair
#define endl "\n"
#define F first
#define S second
#define vi vector<int>
#define vii vector< vector<int> >
#define vpi vector< pair<int,int> >
#define viii vector< vector<vector<int> > >
#define cd complex<double>
#define PI acos(-1)
#define pie 3.14159265358979323846
#define all(c) (c).begin(),(c).end()
#define prec(n) fixed << setprecision(n)
#define print_time {cout << flush; cerr << endl << "Time taken: " << fixed << setprecision(3) << 1.0 * clock() / CLOCKS_PER_SEC << " secs\n";}
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b)) / gcd((a),(b))
#define bc(n) __builtin_popcountll(n)
#define leadzero(a) __builtin_clz(a)        // count leading zeroes
#define trailzero(a) __builtin_ctz(a)       // count trailing zeroes
#define bitcount(a) __builtin_popcount(a)   // count set bits
#define lps(v,x) (lower_bound(all(v),x)-v.begin())
#define ups(v,x) (upper_bound(all(v),x)-v.begin())
typedef long double ld;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
    X ;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inft = (1LL<<61) ;
const int inf = 5e18;
const int mod = 1e9+7;
int modpow(int x, int n, int mod){
    x %= mod ;
    int res = 1;
    while(n>0){
        if(n & 1)res = res * x % mod;
        x = x*x%mod;
        n>>=1 ;}
    return res;}
const int N = 1e6+1e4+1e2+1 ;
const int M = 3*(1e5+1e3+1e1) ;

#define TRACE
#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<"  ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

signed main()
{
    boost ;
    cin.exceptions(cin.failbit);

    #ifndef ONLINE_JUDGE
       //freopen("input.txt", "r", stdin);
       //freopen("output.txt","w", stdout) ;
    #endif // ONLINE_JUDGE

    int n ;
    cin >> n ;
    int mx ;
    cin >> mx ;

    n-- ;
    int ans=1 ;
    while(n--)
    {
        int a ;
        cin >> a ;
        if(a>=mx)
        {
            ans++ ;
            mx=max(mx,a) ;
        }
    }

    cout << ans << endl ;
return 0 ;
}



