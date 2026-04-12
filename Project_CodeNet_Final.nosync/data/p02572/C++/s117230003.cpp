#include <stdio.h>
#define MOD         (1000000000+7)
typedef long long ll;

int main(){
    ll n, a[200000]={0}, sum=0, tmp=0;
    scanf("%lld", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", &a[i]);
        tmp += a[i];
        tmp %= MOD;
    }
    for(int i=0; i<n; i++){
        tmp -= a[i];
        if( tmp < 0 ){ tmp += MOD; }
        sum += (a[i] * tmp);
        sum %= MOD;
    }
    printf("%lld\n", sum);
    return 0;
}