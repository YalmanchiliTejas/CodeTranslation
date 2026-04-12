#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    ll i,ans=0;
    if(k == 0)
        ans = n*n;
    else
        for(i=k+1;i<=n;i++)
        {
            ans += (i-k)*(n/i);
            ll b = (n/i)*i+k;
            if(n >= b)
                ans += n-b+1;
        }
    printf("%lld\n",ans);
    return 0;
}
