#include <cstdio>
#define ll long long

const ll MOD = 1e9+7;
const int MAX = 2e5+10;
ll a[MAX], pre[MAX];

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        if (i == 0) {pre[i] = a[i]; continue;}
        pre[i] = a[i] + pre[i-1];
    }
    ll ans = 0, sum = 0;
    for (int i = 0; i < n-1; i++){
        sum = pre[n-1] - pre[i];
        ans = ans+(sum%MOD*a[i]%MOD)%MOD;
    }
    printf("%lld\n", ans%MOD);
    return 0;
}
