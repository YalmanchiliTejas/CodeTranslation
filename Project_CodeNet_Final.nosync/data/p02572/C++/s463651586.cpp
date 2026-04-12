#include <cstdio>
#include <algorithm>
long long s,ans;
int n,a[200003];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    std::sort(a+1,a+1+n);
    for(int i=2;i<=n;i++) s=(s+a[i-1])%1000000007,ans=(ans+s*a[i])%1000000007;
    printf("%lld\n",ans);
    return 0;
}