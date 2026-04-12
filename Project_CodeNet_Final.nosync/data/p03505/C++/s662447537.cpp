#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
    ll k,a,b;
    scanf("%lld%lld%lld",&k,&a,&b);
    ll ans,s;
    if(a >= k)
    {
        printf("1\n");
        return 0;
    }
    if(a <= b)
    {
        printf("-1\n");
        return 0;
    }
    s = (k-a)/(a-b);
    ans = s*(a-b)+a;
    s = s*2+1;
    if(ans >= k)
        printf("%lld\n",s);
    else
        printf("%lld\n",s+2);
    return 0;
}
