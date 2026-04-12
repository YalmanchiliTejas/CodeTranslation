#include<bits/stdc++.h>
#define int long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w", stdout);
    #endif
    IOS;
    int n,mod;
    mod=1000000007;
    cin>>n;
    int a[n],s=0;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
        s=s+a[i];
    }
    int ans=0;
    for (int i = 0; i < n-1; ++i)
    {
        s-=a[i];
        ans=ans+(a[i]*(s%mod))%mod;
    }
    cout<<ans%mod;
    #ifndef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0;
}       