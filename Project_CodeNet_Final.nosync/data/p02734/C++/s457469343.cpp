
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

const int N=3005;
const int mod=998244353;

int n,s,a[N],dp[N][N];
int rec(int i,int sum){
    if(sum==0) return n-i+2;
    if(i>n or sum<0) return 0;
    int &cache=dp[i][sum];
    if(cache!=-1) return cache;
    return cache=(rec(i+1,sum)+rec(i+1,sum-a[i]))%mod;
}
signed main(){
    FastIO;
    cin>>n>>s;
    rep(i,1,n) cin>>a[i];
    memset(dp,-1,sizeof dp);
    int ans=0;
    rep(i,1,n) ans=(ans+rec(i,s))%mod;
    cout<<ans;
    return 0;
}
