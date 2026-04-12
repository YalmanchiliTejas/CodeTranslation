#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
 
    int a,b,c,x,y,sum=0;
    scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
    if(a+b<2*c)
    {
        printf("%d\n",a*x+b*y);
    }
    else
    {
        if(x<=y)
        {
            sum=2*x*c;
            if(2*c<b)
                sum=sum+2*abs(y-x)*c;
            else
                sum=sum+(y-x)*b;
        }
        else
        {
            sum=2*y*c;
            if(2*abs(y-x)*c<(x-y)*a)
                sum=sum+2*abs(x-y)*c;
            else
                sum=sum+(x-y)*a;
        }
 
     printf("%d",sum);
    }
 
    return 0;
}
