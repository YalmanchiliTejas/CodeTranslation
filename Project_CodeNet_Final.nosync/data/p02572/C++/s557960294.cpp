#include <bits/stdc++.h>

const int moder = int(1e9) + 7;
const int inv2 = (moder + 1) / 2;

int main(){
    int n;
    scanf("%d", &n);
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        sum1 = (sum1 + x) % moder;
        sum2 = (sum2 + 1ll * x * x) % moder;
    }
    int ans = (1ll * sum1 * sum1 - sum2) % moder;
    ans = 1ll * ans * inv2 % moder;
    ans += ans < 0 ? moder : 0;
    printf("%d\n", ans);
    return 0;
}