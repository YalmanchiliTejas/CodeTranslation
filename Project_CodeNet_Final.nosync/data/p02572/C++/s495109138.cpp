#include <cstdio>
long long num[300005], he[300005];
int main() {
    long long n = 0;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &num[i]);
    }
    for (int i = n; i >= 1; i--) {
        he[i] = (he[i + 1] + num[i]) % 1000000007;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        //printf("%lld * %lld\n", he[i + 1], num[i]);
        ans = (ans + he[i + 1] * num[i]) % 1000000007;
    }
    printf("%lld\n", ans);
    return 0;
}