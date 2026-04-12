#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,x,y;
    long long ans;
    cin>>a>>b>>c>>x>>y;
    if((a+b)<=(2*c))
    {
        ans=(a*x)+(b*y);
    }
    else
    {
       ans=c*2*min(x,y);
       if(x>y&&a<(2*c))
       {
           ans=ans+(a*(x-y));
       }
       else if(y>x&&b<(2*c))
       {
           ans=ans+(b*(y-x));
       }
       else
       {
           ans=ans+(2*c*fabs(x-y));
       }


    }
    cout<<ans<<endl;
    return 0;
}
