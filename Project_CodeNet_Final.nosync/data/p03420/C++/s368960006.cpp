#include <cstdio>
int n,k;
long long ans;
int main()
{
	scanf("%d%d",&n,&k);
    for(int x=k;x<=n-1;x++)
	{
        int t=n-x;
        for(int b=x+1;b<=n;)
        {
            int N=0;
            if(t/b)N=t/(t/b);
            else N=n;
            ans+=1ll*(N-b+1)*((t/b)+(x>0));
            b=N+1;
        }
    }
    printf("%lld\n",ans);
}