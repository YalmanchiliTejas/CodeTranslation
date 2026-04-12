#include <bits/stdc++.h>    
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#pragma GCC optimize("O3")
//using namespace __gnu_pbds; 
#define fastio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define pb  push_back
#define show(x) cout<<(#x)<<" : "<<x<<endl;
#define ll  long long
#define ld  long double
#define fill(a,val) memset(a,val,sizeof(a))
#define mp  make_pair
#define ff  first
#define ss  second
#define pii pair<ll,ll>
#define sq(x) ((x)*(x))
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define endl "\n"
#define int long long 
#define printclock cerr<<"Time : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n";
const ll MOD     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ll N       = 1000*1000+5;
const ll N2      = 2000*1000*10;
const ld PI  = 3.141592653589793;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> tree_set;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
ll lcm(ll a , ll b){return (a*b)/gcd(a,b);}
signed main()
{
    fastio();
    //cout<<fixed<<setprecision(20);
    //CHECK for LONG LONG and LONG DOUBLE
    /*comment for all except cc/cf    
    #ifndef ONLINE_JUDGE    
           freopen("input.txt","r",stdin);
           freopen("output.txt","w",stdout);
    #endif//*/
    int n,m;
    cin>>n>>m;

    n==m ? cout<<"Yes" : cout<<"No" ; 
    printclock;
    
}