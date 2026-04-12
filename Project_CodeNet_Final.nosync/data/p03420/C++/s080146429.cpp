#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n,k;
    while(~scanf("%lld%lld",&n,&k))
    {
        ll res=0LL;
        for(ll b=k+1;b<=n;b++)
        {
            res+=n/b*(b-k);
            res+=max(0LL,(n%b)-k+1);
        }
        if(k==0) res=n*n;
        printf("%lld\n",res);
    }
}
