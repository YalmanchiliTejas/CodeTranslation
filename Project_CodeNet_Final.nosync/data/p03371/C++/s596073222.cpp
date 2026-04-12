#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <utility>

using namespace std;

int main()
{
    int a, b, c, x, y, ans=0;
    cin>>a>>b>>c>>x>>y;
    if (x<=y)
    {
        if (a+b<=2*c) ans+=a*x+b*y;
        else
        {
            ans+=x*2*c;
            if (b<=2*c) ans+=b*(y-x);
            else ans+=(y-x)*2*c;
        }
    }
    else
    {
        if (a+b<=2*c) ans+=a*x+b*y;
        else
        {
            ans+=y*2*c;
            if (a<=2*c) ans+=a*(x-y);
            else ans+=(x-y)*2*c;
        }
    }
    cout<<ans<<endl;
    return 0;
}
