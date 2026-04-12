#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,x,y,i;long long  k=0;
    long long t=0;
    scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    if(c*2>=(a+b))
        {long long r=0;
        r=x*a+y*b;
            printf("%lld\n",r);return 0;}
    else
    {
        if(x>=y)
            {k=c*x*2;}
        else
            {k=c*y*2;}
        /*if(x%2)
            {t=t+a;x=x-1;}
        if(y%2)
           {
               t=t+b;y-=1;
           }*/
        int p;
        if(x>=y)
            {p=y;}
        else
            {p=x;}
        t=t+p*2*c;
        if(x>y)
            t=t+(x-y)*a;
        else if(y>=x)
            t=t+(y-x)*b;
        if(k>=t)
             printf("%lld\n",t);
         else
            printf("%lld\n",k);
    }

    return 0;
}
