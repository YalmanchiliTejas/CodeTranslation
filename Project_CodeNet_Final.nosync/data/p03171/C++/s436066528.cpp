
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
const int mod=1e9+7;

ll n,a[N],dp[N][N][2];
ll rec(int s,int e,bool turn){
    if(s>e) return 0;
    ll &cache=dp[s][e][turn];
    if(cache) return cache;
    return cache=(turn?min(-a[s]+rec(s+1,e,turn^1),-a[e]+rec(s,e-1,turn^1)):max(a[s]+rec(s+1,e,turn^1),a[e]+rec(s,e-1,turn^1)));
}
signed main(){
    FastIO;
    cin>>n;
    rep(i,1,n) cin>>a[i];
    cout<<rec(1,n,0);
    return 0;
}
