#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
typedef long long LL;
LL my_max(LL a,LL b)
{
    return a>b ? a:b;
}
int main()
{
    LL N,M;
    scanf("%lld %lld",&N,&M);
    LL sum=0;
    for(LL i=M+1;i<=N;i++)
    {
        LL a=my_max(0,N%i-M+1);
        LL now=N-N%i;
        now/=i;
        sum+=(i-M)*now;
        sum+=a;
    }
    if(M==0)
        sum-=N;
    printf("%lld\n",sum);
    return 0;
}