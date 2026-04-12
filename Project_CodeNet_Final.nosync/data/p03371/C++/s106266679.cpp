#include<bits/stdc++.h>
using namespace std;
main()
{
    long long  a,b,c,x,y,z,d,m1,m2,m3;
    cin>>a>>b>>c>>x>>y;
    z=min(x,y);
    if(x>y)d=(x-y)*a;
    else d=(y-x)*b;
    m2=d+(z*2*c);
    m3=max(x,y)*2*c;

    m1=a*x + b*y;
    m1=min(m1,m2);
    m1=min(m1,m3);
    cout<<m1<<endl;

    return 0;
}
