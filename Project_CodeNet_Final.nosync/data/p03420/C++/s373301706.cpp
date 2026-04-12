#include <iostream>
#include <cstdio>
typedef long long LL;
using namespace std;

int main()
{
    LL n,k,ans;
    while(scanf("%lld%lld",&n,&k) == 2)
    {
        ans = 0;
        if(k)
        {
            for(LL i = k + 1; i <= n; i++)
            {
                LL yu = n%i - k + 1;
                ans += n/i*(i-k) + (yu>0?yu:0);
            }
        }
        printf("%lld\n",k?ans:n*n);
    }
    return 0;
}
