#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Maxn=2e5+10;
const ll Mod=1e9+7;
ll sum[Maxn],a[Maxn];
int main() {
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++)    cin>>a[i];
    for(ll i=1;i<=n;i++)    sum[i]=(sum[i-1]+a[i])%Mod;
    ll ans=0;
    for(ll i=1;i<=n-1;i++){
        ans=((ans+a[i]*(sum[n]-sum[i])%Mod)+Mod)%Mod;
    }
    cout<<ans%Mod;
    return 0;
}
