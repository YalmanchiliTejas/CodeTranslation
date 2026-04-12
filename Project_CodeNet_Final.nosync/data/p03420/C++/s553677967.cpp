#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k, i;
    long long ans = 0;
    
    scanf("%d %d", &n, &k);
    
    if (k == 0) {
        printf("%lld\n", (long long)n * n);
        return 0;
    }
    
    for (i = k + 1; i <= n; i++) {
        ans += n / i * (i - k);
        ans += max(n % i - k + 1, 0);
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
