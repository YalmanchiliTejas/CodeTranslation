#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int a,b,c,x,y,sum=0,sum1=0;
    scanf("%d %d %d %d %d",&a,&b,&c,&x,&y);
    if(a+b<=2*c)
    {
        sum=sum+x*a+y*b;
        printf("%d\n",sum);
    }
    else
    {
        if(x>=y)
        {
            sum=sum+c*2*y;
            sum=sum+(x-y)*a;
            sum1=sum1+c*2*x;
        }
        else
        {
            sum=sum+c*2*x;
            sum=sum+(y-x)*b;
            sum1=sum1+c*2*y;
        }
        if(sum1>=sum)
            printf("%d\n",sum);
        else
            printf("%d\n",sum1);
    }
    return 0;
}
