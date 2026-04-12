#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define M 10000000000000000
using namespace std;
typedef unsigned long long ull;
int main()
{
    ull A,B,C,x,y;
    while(scanf("%llu %llu %llu %llu %llu",&A,&B,&C,&x,&y)!=EOF)
    {
        ull Min=M;
        ull sum=0;
        sum =sum + A*x + B*y;
        Min=min(sum,Min);
        sum=0;

        ull a=max(x,y);
        sum = sum + 2*a*C;
        Min=min(Min,sum);
        sum =0;

        if(x>y)
        {
            sum=sum+2*y*C;
            ull b=x-y;
            sum=sum+b*A;
            Min=min(Min,sum);
            sum=0;
        }
        else
        {
            sum=sum+2*x*C;
            ull b=y-x;
            sum=sum+b*B;
            Min=min(Min,sum);
            sum=0;
        }
        printf("%llu\n",Min);
    }
    return 0;
}
