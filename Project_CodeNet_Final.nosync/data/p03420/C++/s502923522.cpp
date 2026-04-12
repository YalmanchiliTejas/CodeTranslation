#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans=0;
int main()
{
    //freopen("ce.in","r",stdin);
    scanf("%d%d",&n,&k);
    for(int b=k+1;b<=n;++b)
    {
        int num=(n+1)/b;
        ans+=1LL*num*(b-k);
        int left=n+1-num*b;
        --left;
        ans+=max(0,left-k+1);
        if(k==0) --ans;
    }
    printf("%lld\n",ans);
    return 0;
}
