#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    vector<ll> a(n+1,0);    
    for(int i=0;i<n;i++)    
        cin>>a[i+1];
    ll ans = 0;
    ll suf = 0;
    for(int i=n-1;i>0;i--)
    {
        suf+=a[i+1];
        suf%=MOD;
        ans += (a[i]*1ll*suf)%MOD;
    }
    ans%=MOD;
    
    cout<<ans<<'\n';
    
    return 0;
}

