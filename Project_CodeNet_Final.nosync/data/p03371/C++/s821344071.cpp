#include<bits/stdc++.h>
using namespace std;
main()
{
    long long a,b,c,x,y,t,g,h,k,l;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
    t=(a*x)+(b*y);
    if(x>y)
    {
        g=(2*x)*c;
        h=((2*y)*c)+((x-y)*a);
    }
    else
    {
        g=(2*y)*c;
        h=((2*x)*c)+((y-x)*b);

    }
    if(t<=g&&t<=h)
        printf("%lld\n",t);
    else if(g<=t&&g<=h)
        printf("%lld\n",g);
        else
            printf("%lld\n",h);
        return 0;



}

