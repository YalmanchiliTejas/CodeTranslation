#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
inline ll Function(ll n,ll k)
{
    if(k==0)
    {
        return n*n;
    }
    ll sum=0;
    for(ll i=k+1;i<=n;i++){
        sum+=(i-k)*(n/i);
        if(n%i>=k)sum+=(n%i-k+1);
    }
    return sum;
}

int main()
{
    ll n,k;
    while (scanf("%lld%lld",&n,&k)!=EOF) {
        printf("%lld\n",Function(n,k));
    }
    return 0;
}