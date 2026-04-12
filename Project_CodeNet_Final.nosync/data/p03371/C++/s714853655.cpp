#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=min(x*a+y*b,max(x,y)*2*c);
    if (x<y)
        ans=min(ans,x*2*c+(y-x)*b);
    else
        ans=min(ans,y*2*c+(x-y)*a);
    cout<<ans<<endl;
}