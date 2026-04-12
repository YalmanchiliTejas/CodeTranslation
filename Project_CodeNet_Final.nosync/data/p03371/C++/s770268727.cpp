#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,c,x,y,e,f,g;
    scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&x,&y);
    g=(a*x)+(b*y);
    if(x>y)
    {
        e=(2*x)*c;
        f=((2*y)*c)+((x-y)*a);
    }
    else
    {
        e=(2*y)*c;
        f=((2*x)*c)+((y-x)*b);
    }
    if(e<=g && e<=f)
        printf("%lld\n",e);
   else if(f<=e && f<=g)
        printf("%lld\n",f);
   else
        printf("%lld\n",g);
    return 0;
}
