#include <bits/stdc++.h>    
//#include <ext/pb_ds/assoc_container.hpp> 
//#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const ll mod     = 1000*1000*1000+7;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7;
const ll MOD2    = 998244353;
const ll N       = 1000 * 1000 + 10;
const ll N2      = 70;
const ld PI      = 3.141592653589793;
//template<class T>using onset=tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);} 
ll power(ll x,ll y,ll p = LLONG_MAX ){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
void solve(){
  #ifndef ONLINE_JUDGE  
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
}
signed main(){
    fastio();
    //cout<<fixed<<setprecision(20);
    ll n; 
    cin>>n; 
    ll a[n];
    for(ll i=0;i<n;i++){
      cin>>a[i];
    }
    ll ans=0,sum=0;
    for(ll i=0;i<n;i++){
      sum+=a[i];
    }
    for(ll i=0;i<n;i++){
      sum-=a[i];
      ans=ans%mod+(sum%mod*a[i]%mod)%mod; 
    }
    cout<<ans; 
    return 0;
}   