#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int n,k;
long long ans;
int main()
{
    scanf("%d%d",&n,&k);
    for(int b=k+1;b<=n;b++)
    {
        ans+=n/b*(b-k);
        if(k>0)ans+=max(0,n%b-k+1);
        else ans+=max(0,n%b-k);
    }
    printf("%lld",ans);
}