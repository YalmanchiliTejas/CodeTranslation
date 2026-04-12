#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,c,x,y,ans,a1,a2,a3;
    cin>>a>>b>>c>>x>>y;
    a1=a*x+b*y;
    a2=2*c*max(x,y);
    if(x>y)
    {
        a3=y*c*2+(x-y)*a;
    }
    else a3=x*c*2+(y-x)*b;
    ans=min(a1,min(a2,a3));
    cout<<ans<<endl;
    return 0;
}
