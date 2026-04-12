#include <bits/stdc++.h>
#define NMAX 300005

using namespace std;
using ll = long long;
using pll = pair<ll,ll>;
const ll MOD=1e9+7;
int main()
{
    ll n,x,sum=0,ans=0;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>x;
        ans+=x*sum%MOD;
        ans%=MOD;
        sum+=x;
        sum%=MOD;
    }
    cout<<ans;
    return 0;
}
