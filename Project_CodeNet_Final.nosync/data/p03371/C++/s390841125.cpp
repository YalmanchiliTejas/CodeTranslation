#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll ans=max(x,y)*2*c;
    ans=min(ans,min(x,y)*2*c+(y>x?(y-x)*b:(x-y)*a));
    ans=min(ans,a*x+b*y);
    cout<<ans;
    return 0;
}