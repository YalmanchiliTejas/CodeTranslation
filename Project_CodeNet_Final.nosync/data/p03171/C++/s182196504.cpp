/*input
6
4 2 9 7 1 5
*/
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#pragma GCC optimize("unroll-loops,no-stack-protector")
//order_of_key #of elements less than x
// find_by_order kth element
using ll = long long;
using ld = long double;
using pii = pair<ld,ld>;
#define f first
#define s second
#define pb push_back
#define REP(i,n) for(ll i=0;i<n;i++)
#define FILL(n,x) memset(n,x,sizeof(n))
#define ALL(_a) _a.begin(),_a.end()
#define sz(x) (int)x.size()
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
const ll INF64=4e18;
const int INF=1e6+1;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld eps=1e-9;
#define lowb(x) x&(-x)
#define MNTO(x,y) x=min(x,(__typeof__(x))y)
#define MXTO(x,y) x=max(x,(__typeof__(x))y)
ll sub(ll a,ll b){
    ll x=a-b;
    while(x<0) x+=MOD;
    while(x>MOD) x-=MOD;
    return x;
}
ll mult(ll a,ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ll mypow(ll a,ll b){
    if(b<=0) return 1;
    ll res=1LL;
    while(b){
        if(b&1) res=(res*a);
        if(res>1e10) return 1e11;
        a=(a*a);
        b>>=1;
    }
    return res;
}
const ll maxn=3005;
const ll maxlg=__lg(maxn)+2;
ll dp[maxn][maxn];
int arr[maxn];
int main(){
    int n;
    cin>>n;
    ll sum=0;
    REP(i,n){
        cin>>arr[i];
        dp[i][i]=arr[i];
        sum+=arr[i];
    }
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            dp[i][j]=max(arr[j]-dp[i][j-1],arr[i]-dp[i+1][j]);
        }
    }
    cout<<dp[0][n-1];
}