#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;
void Digvijay()
{
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> pref(n+2,0);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
       
    }
    pref[n]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        pref[i+1]=pref[i+2]+a[i];
        pref[i+1]%=mod;
    }

    int ans=0;
    //for(auto it:pref)cout<<it<<" ";
    for(int i=1;i<=n;i++)
    {
        ans = (ans%mod + (a[i-1]%mod*pref[i+1]%mod)%mod)%mod;
    }
    cout<<ans<<"\n";

}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    //cin>>_;
    for(int __=1;__<=_;__++)
    {
        Digvijay();
    }
}

