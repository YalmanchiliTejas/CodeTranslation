#include <cstdio>
#include <algorithm>
long long s,ans;//s和ans要开long long
int n,a[200003];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        s=(s+a[i-1])%1000000007;//求前i-1的前缀和
        ans=(ans+s*a[i])%1000000007;//加上s*a[i]，两个都要取模
    }
    printf("%lld\n",ans);
    return 0;
}