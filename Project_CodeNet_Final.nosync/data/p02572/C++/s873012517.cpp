#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 0x3f3f3f3f
const ll mod=1e9+7;
ll suffixSum[200005];
ll a[200005];
int main(void)
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    suffixSum[n]=0;
    for(int i=n-1;i>=0;--i) suffixSum[i]=(suffixSum[i+1]+a[i])%mod;
    ll ans=0;
    for(int i=0;i<n;++i)
        ans=(ans+a[i]*suffixSum[i+1]%mod)%mod;
    cout<<ans<<endl;
    return 0;
}