#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX=1e9+7;
int main()
{
    ll  a,b,c,x,y,Min,ab,ans;
    cin>>a>>b>>c>>x>>y;
    if((a+b)>=2*c)//buy c
    {
        if(x>y)
            Min=y;
        else
            Min=x;
        ans=Min*c*2;
        // cout<<ans<<endl;
        int f=1;
        if(2*c<a || 2*c<b)
        {
            if(2*c<a && x>y)
                {ans+=2*c*(x-y);f=0;}
            if(2*c<b && y>x)
                {ans+=2*c*(y-x);f=0;}
        }
            if(x>y && f)
                ans+=a*(x-y);
            if(x<=y && f)
                ans+=b*(y-x);

    }
    else
    {
        ans=x*a+y*b;
    }
    cout<<ans<<endl;
    return 0;
}
