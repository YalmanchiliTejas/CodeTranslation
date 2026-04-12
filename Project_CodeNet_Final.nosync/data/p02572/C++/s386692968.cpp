#include <bits/stdc++.h>
using namespace std;

const int N=2e5+100;
const int mod=1e9+7;
typedef long long ll;
ll a[N];
ll sum[N];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sum[n]=a[n];
    for(int i=n-1;i>=2;i--){
        sum[i]=(sum[i+1]+a[i])%mod;
    }

    ll ans=0;
    for(int  i=1;i<=n-1;i++){
        ans=(ans+a[i]*sum[i+1]%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
