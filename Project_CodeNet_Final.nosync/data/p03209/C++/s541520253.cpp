#include <stdio.h>
#include <math.h>
#include <stdlib.h>
long long num[55],meat[55];
long long dfs(int,long long);
int main(void)
{
    int n,i;
    long long x,sum;
    scanf("%d%lld",&n,&x);
    num[0]=1;meat[0]=1;
    for(i=1;i<=n;i++)
    {
        num[i]=2*num[i-1]+3;
        meat[i]=2*meat[i-1]+1;
    }
    sum=dfs(n,x);
    printf("%lld\n",sum);
    return 0;
}
long long dfs(int n,long long x)
{
    long long sum=0;
    if(n==0)sum=1;
    if(x==0){sum=0;
    return 0;}
    if(num[n]<=x)sum=meat[n];
    else if(x<=num[n]/2)sum+=dfs(n-1,x-1);
    else if(x==num[n]/2+1)sum+=meat[n-1]+1;
    else if(x>num[n]/2+1)sum+=meat[n-1]+1+dfs(n-1,x-num[n]/2-1);
    return sum;
}
