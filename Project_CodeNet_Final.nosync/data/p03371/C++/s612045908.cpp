#include<bits/stdc++.h>
using namespace std;

int main ()
{

    ios::sync_with_stdio (false) ;
    int a ,b,c ,x,y;
    while (cin>>a>>b>>c>>x>> y)
    {
        int ans = 0;
        if (a+b>2*c)
        {
            int t = min (x,y) ;
            ans+=2*c*t;
            x-=t;
            y-=t;
        }

        if (a<2*c)
        ans+=x*a;
        else ans+=2*c*x;
        if (b<2*c)
        ans+=b*y;
        else ans+=y*2*c;
    cout<<ans<<endl;
    }
    return 0;
}