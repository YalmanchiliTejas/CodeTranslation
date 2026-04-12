#include <bits/extc++.h>
using namespace std;
using i64=int64_t;

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    i64 ans=0;
    i64 acc=0;
    int mod=1e9+7;
    for(int i=0; i<n; ++i)
    {
        i64 a; cin>>a;
        ans+=a*acc%mod;
        if(ans>=mod) ans-=mod;
        acc+=a;
        if(acc>=mod) acc-=mod;
    }
    cout<<ans<<"\n";
}
