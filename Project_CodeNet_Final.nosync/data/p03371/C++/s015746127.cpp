#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,x,y,t,q,r,max=0;
    cin>>a>>b>>c>>x>>y;
    t=x*a;
    q=y*b;
    max=t+q;
    if(x>y)
    {
        r=(x*2)*c;
        t= (y*2)*c;
        q= t+ ((x-y)*a);
    }
    else
    {
        r= (y*2)*c;
        t= (x*2)*c;
        q= t+ ((y-x)*b);
    }
    if(r<max)
        max=r;
    if(q<max)
        max=q;
    cout<<max<<endl;
    return 0;
}
