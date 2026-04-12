#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[3010], n, res[3010][3010];

bool vis[3010][3010];
ll dp(ll st, ll en)
{
    if(st==en)
    {
        if(n%2==1) return a[st];
        else return -a[st];

    }


    if(vis[st][en]!=0) return res[st][en];
    ll ans;
    if((n-(en-st))%2==1) ans=max(a[st]+dp(st+1, en), a[en]+dp(st, en-1));
    else ans=min(dp(st+1, en)-a[st], dp(st, en-1)-a[en]);

    res[st][en]=ans;
    vis[st][en]=1;
    return ans;
}

main()
{
    ll i, j;

    cin>>n;

    for(i=0; i<n; i++) scanf("%lld", &a[i]);

    j=dp(0, n-1);

    cout<<j<<endl;
}
