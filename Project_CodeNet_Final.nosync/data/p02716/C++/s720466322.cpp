
/**
 *    Coded by : lucky_21
 *               --------Lokesh Singh
**/

#include<bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

#define     F           first
#define     S           second
#define     pb          push_back
#define     lb          lower_bound
#define     ub          upper_bound
#define     pii         pair<int,int>
#define     all(x)      x.begin(),x.end()
#define     fix         fixed<<setprecision(10)
#define     rep(i,a,b)  for(int i=int(a);i<=int(b);i++)
#define     repb(i,b,a) for(int i=int(b);i>=int(a);i--)
#define     FastIO      ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

typedef double db;
typedef long long ll;

const int N=2e5+5;
const int mod=1e9+7;

int n,a[N];
ll dp[N][5];
ll rec(int i,int j){
    if(i==n and j==4) return 0;
    if(i>n) return 0;
    ll &cache=dp[i][j];
    if(cache!=1e18) return cache;
    if(j==4) return cache=a[i]+max({rec(i+4,2),rec(i+3,3),rec(i+2,4)});
    if(j==3) return cache=a[i]+max(rec(i+3,2),rec(i+2,3));
    else return cache=a[i]+rec(i+2,2);
}
signed main(){
    FastIO;
    cin>>n;
    rep(i,1,n){
        cin>>a[i];
        rep(j,0,4) dp[i][j]=1e18;
    }
    if(n==3) return cout<<max({a[1],a[2],a[3]}),0;
    ll ans;
    if(n&1) ans=max({rec(1,4),rec(2,3),rec(3,2)});
    else ans=max(rec(1,3),rec(2,2));
    cout<<ans;
    return 0;
}
