//#pragma GCC optimize("-Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("avx2")  //Enable AVX
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
//order_of_key(x) : number of items less than x
//find_by_order(x) : iterator to x

#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define fastio              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define F                   first
#define S                   second
#define all(v)              (v).begin(),(v).end()

const ld pi=3.14159265359;
ll INF=1e18+10;
ll MOD=998244353;
ll mod=1e9+7;

inline ll add(ll a,ll b,ll m){
    if((a+b)>=m)return (a+b)%m;
    return a+b;
}

inline ll mul(ll a,ll b,ll m){
    if((a*b)<m)return a*b;
    return (a*b)%m;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ll n;cin>>n;
    ll a[n+1];mem(a,0);
    rep(i,1,n+1)cin>>a[i];
    ll dp[n+1][3];mem(dp,0);
    rep(i,0,n+1)dp[i][0]=dp[i][1]=dp[i][2]=-INF;
    dp[1][0]=a[1];
    dp[2][1]=a[2];
    dp[3][0]=a[1]+a[3];dp[3][2]=a[3];
    rep(i,4,n+1){
        dp[i][0]=max(dp[i-2][0]+a[i],dp[i][0]);
        dp[i][1]=max({dp[i-3][0]+a[i],dp[i-2][1]+a[i],dp[i][1]});
        dp[i][2]=max({dp[i-4][0]+a[i],dp[i-3][1]+a[i],dp[i-2][2]+a[i],dp[i][2]});
    }
    if(n&1)cout<<max({dp[n][2],dp[n-1][1],dp[n-2][0]});
    else cout<<max(dp[n][1],dp[n-1][0]);
}