#include <bits/stdc++.h>
using namespace std;
long long a,b,c,x,y,z,d,s,z1,d1,g;
int main()
{
    cin>>a>>b>>c>>x>>y;
    z=min (x,y);
    z*=2;
    d=z*c;
    if (x<y)
    {
        d+=(y-x)*b;
    }
    else if (x>y)
    {
        d+=(x-y)*a;
    }
    s=(a*x)+(b*y);
    z1=max (x,y);
    z1*=2;
    d1=z1*c;
    g=min (s,d);
    cout<<min (g,d1);
    return 0;
}
