#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
ll sum;
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(k==0)
    {
        printf("%lld\n",n*n);
        return 0;
    }
    for(int i=k+1;i<=n;i++)
    {
        sum+=(n/i)*(i-k);
        if(n%i>=k)
            sum+=(n%i-k+1);
    }
    printf("%lld\n",sum);
    return 0;
}
