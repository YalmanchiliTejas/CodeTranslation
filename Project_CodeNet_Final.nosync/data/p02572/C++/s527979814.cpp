#include <iostream>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int maxn=2e5+10;
ll pre[maxn],a[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pre[i]=(pre[i-1]+a[i])%mod;
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        ll tmp=(a[i]%mod)*( (pre[n]+mod-pre[i])%mod )%mod;
        ans=(ans+tmp)%mod;
    }
    cout<<ans<<endl;
    return 0;
}
