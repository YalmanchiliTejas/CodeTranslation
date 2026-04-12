#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll mod=1e9+7,maxn=1e6+7;
ll dp[maxn];///dp[i]表示只从前i个中选择i/2个
ll sum[maxn];
ll a[maxn],n;
int main(){
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i>1) sum[i]=sum[i-2]+a[i];
        else sum[i]=a[i];
    }
    for(ll i=2;i<=n;i++)
        if(i%2) dp[i]=max(dp[i-2]+a[i],dp[i-1]);
        else dp[i]=max(dp[i-2]+a[i],sum[i-1]);
    cout<<dp[n];
    return 0;
}
