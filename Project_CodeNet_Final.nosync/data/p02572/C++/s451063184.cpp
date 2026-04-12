#include<bits/stdc++.h>
using namespace std;
const int p=1000000007;
long long s[200003],ans,q[200003];
int n,m;
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%lld",&s[i]);
        q[i]=(s[i]+q[i-1])%p;
    }
    for(int i=2;i<=n;++i)
    {
        ans=(ans+(s[i]*(q[i-1])%p)%p)%p;
    }
    printf("%lld\n",ans);
    return 0;
}
