#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define all(x) begin(x),end(x)
#define pii pair<int,int>
#include <bits/stdc++.h>
#define pll pair<ll,ll>
#define vi vector<int>
#define ld long double
#define ll long long
#define pb push_back
#define mid (l+r)/2
#define S second
#define F first
using namespace std;
const ll mod = 998244353;
ll n,s,ans;
ll a[3009];
ll dp[3009][3009];
ll bt(ll id,ll sum){
    if(sum > s) return 0;
    if(sum == s) return n-id+1;
    if(id == n) return 0;
    ll &ret = dp[id][sum];
    if(ret != -1) return ret;
    ret = bt(id+1,sum);
    ret = (ret+bt(id+1,sum+a[id]))%mod;
    return ret;
}
int main(){
    fast,cin>>n>>s; mem(dp,-1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        ans = (ans+bt(i,0))%mod;
    }
    cout<<ans<<endl;
}
