#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    long long A,B,C,X,Y,ans;
    scanf("%lld%lld%lld%lld%lld",&A,&B,&C,&X,&Y);
    ans=(1LL<<60);
    for(long long i=0;i<=max(X,Y);i++)
        ans=min(ans,2*i*C+max(0LL,X-i)*A+max(0LL,Y-i)*B);
    printf("%lld\n",ans);
    return 0;
}
