#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long a,b,c,x,y,ans;
    cin>>a>>b>>c>>x>>y;
    ans=max(x,y)*2*c;
    ans=min(ans,min(x,y)*2*c+((x>y)?(x-y)*a:(y-x)*b));
    ans=min(ans,a*x+b*y);
    cout<<ans;
    return 0;
}