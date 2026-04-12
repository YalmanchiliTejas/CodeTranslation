#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
ll n,cnt=0;
ll a[N],sum[N];
string s1,s2;
int main() {
//    freopen("../in.in", "r", stdin);
//    freopen("../out.out","w",stdout);
    ios::sync_with_stdio(false);
    ll t, i, j = 0;
    ll m, x, y,k;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    for(i=n;i>0;i--) sum[i]=(sum[i+1]+a[i])%mod;
//    for(i=1;i<=n;i++) cout<<sum[i]<<endl;
    ll ans=0;
    for(i=1;i<n;i++){
//        cout<<a[i]<<":"<<sum[n-i]<<endl;
        ans=(ans+a[i]*sum[i+1]%mod)%mod;
    }
    cout<<ans<<endl;
    return 0;
}