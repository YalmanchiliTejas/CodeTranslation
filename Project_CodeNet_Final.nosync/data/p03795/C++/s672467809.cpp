#include <cstdio>
int n;
int main()
{
    scanf("%d",&n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=800;
        if(i%15==0) sum-=200;
    }
    printf("%d\n",sum);
}
