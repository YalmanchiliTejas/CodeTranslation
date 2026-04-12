#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int a,b,c,x,y;
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        long long int sum=0,sum1;
        scanf("%d%d",&x,&y);
        if(a+b<=2*c)
            sum=a*x+b*y,sum1=sum+1;
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
        }
        printf("%lld\n",sum<sum1?sum:sum1);
    }
    return 0;
}
