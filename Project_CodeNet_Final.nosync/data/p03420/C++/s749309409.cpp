#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    ll ans=0;
    if(k==0)
    {
        printf("%lld\n",(ll)n*n);
        return 0;
    }
    for(int b=k+1;b<=n;b++)
    {
        ans+=(b-k);
        int t=n/b;
        if(t) ans+=(t-1)*(b-k);
        if(b*t+k<=n)
            ans+=max(0,n-(b*t+k)+1);
    }
    printf("%lld\n",ans);
}
