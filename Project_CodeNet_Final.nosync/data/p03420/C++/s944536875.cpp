#include<bits/stdc++.h>

using namespace std;

#define pq priority_queue
#define MZ 1000000007

int ask(int x,int y,int z)
{
    int now=x/y;
    now=now*(y-z)+max(0,x%y-z+1);
    if(z==0)
        now--;
    return now;
}

int main()
{
    int n,k;
    long long ans=0;
    scanf("%d%d",&n,&k);
    for(int i=k+1;i<=n;i++)
        ans+=ask(n,i,k);
    printf("%lld\n",ans);
    return 0;
}
