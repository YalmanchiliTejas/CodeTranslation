#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int main()
{
long long int a,b,c,x,y;
scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
long long int minn=min(x,y);
long long int sum=0;
if(a+b>c*2)
{
    sum=sum+(c*2*minn);
    if(x>y)
    {
        if(2*c<a)
             sum=sum+2*c*abs(x-y);
        else
             sum=sum+a*abs(x-y);
    }
    else
    {

                if(2*c<b)
             sum=sum+2*c*abs(x-y);
        else
             sum=sum+b*abs(x-y);
    }

}
else
{
    sum=sum+a*x+b*y;
}
printf("%lld",sum);

return 0;
}
