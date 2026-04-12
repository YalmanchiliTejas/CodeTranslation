#include<cstdio>
const long long mod = 1e9+7;
long long a[200005];
long long suffix[200005];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    suffix[n+1] = 0;
    for(int i = n; i >= 1; i--){
        suffix[i] = (suffix[i+1]+a[i])%mod;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        long long add = a[i]*suffix[i+1]%mod;
        ans += add; if(ans>=mod) ans -= mod;
    }
    printf("%lld\n",ans);
    return 0;
}
