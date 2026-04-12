#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t,n,k,a,b,c,p,q,r,s,x,y,z;
    cin>>a>>b>>c>>x>>y;
    s=x*a+y*b;
    if(x<y)
    {
        p=(x+x)*c+(y-x)*b;
        t=min(s,p);
        z=(y+y)*c;
        k=min(t,z);
    }
    else if(x>y)
    {
        q=(y+y)*c+(x-y)*a;
        t=min(s,q);
        z=(x+x)*c;
        k=min(t,z);
    }
    else if(x==y)
    {
        r=(x+x)*c;
        k=min(s,r);
    }
    cout<<k<<endl;
    return 0;
}
