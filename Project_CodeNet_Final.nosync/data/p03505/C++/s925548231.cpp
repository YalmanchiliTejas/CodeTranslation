#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long a,b,c,wow;
    scanf("%lld%lld%lld",&a,&b,&c);
    if(b>=a)
    {
        printf("1\n");
        return 0;
    }
    if(c>=b)
    {
        printf("-1\n");
        return 0;
    }
    if((a-b)%(b-c)>=1) wow=1;
    printf("%lld\n",((a-c-1)/(b-c))*2+1);
    return 0;
}