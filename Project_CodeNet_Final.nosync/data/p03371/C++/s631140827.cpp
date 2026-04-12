#include<stdio.h>
#include <iostream>
#include <algorithm>
#include<string.h>
#include<math.h>
#define M 1000000000000
using namespace std;
typedef unsigned long long ull;
int main()
{
    ull a,b,c,x,y;
    while(scanf("%llu %llu %llu %llu %llu",&a,&b,&c,&x,&y)!=EOF)
    {
        ull Min=M;
        ull sum=0;
        sum=sum+x*a+y*b;
        Min=min(Min,sum);
        //printf("%d*\n",sum);
        sum=0;

        ull B=max(x,y);
        sum=sum+2*B*c;
        Min=min(Min,sum);
        //printf("%d*\n",sum);
        sum=0;


        if(x>y)
        {
            sum=sum+2*y*c+(x-y)*a;
            //printf("%d*\n",sum);
        }
         else
        {

            sum=sum+2*x*c+(y-x)*b;

        }

        Min=min(Min,sum);
        sum=0;
        printf("%llu\n",Min);

    }
    return 0;

}

