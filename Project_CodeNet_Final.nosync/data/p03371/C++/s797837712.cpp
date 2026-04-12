#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int ans=0;

    if(a+b>c+c)ans+=min(x,y)*(c+c);
    else ans+=min(x,y)*(a+b);

    if(a<c+c)ans+=max(0,x-y)*a;
    else ans+=max(0,x-y)*(c+c);

    if(b<c+c)ans+=max(0,y-x)*b;
    else ans+=max(0,y-x)*(c+c);

    cout<<ans<<"\n";

    return 0;
}
