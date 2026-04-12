#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    long long int a,b,c,x,y,min,p[10],i;
    while(scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y)==5)
    {
        if(x>y)
        {
            p[0]=a*x+b*y;
            p[1]=c*2*x;
            p[2]=c*2*y+a*(x-y);
        }
        else
        {
            p[0]=a*x+b*y;
            p[1]=c*2*y;
            p[2]=c*2*x+b*(y-x);
        }
        for(i=0;i<3;i++)
        {
            if(i==0)
                min=p[i];
            else
            {
                if(min>p[i])
                    min=p[i];
            }
        }
        printf("%lld\n",min);
    }
    return 0;
}
