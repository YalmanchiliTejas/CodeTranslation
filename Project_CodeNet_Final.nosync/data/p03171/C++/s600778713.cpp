#include <cstdio>
#include <algorithm>

using namespace std;

int a[3000];
int f[3000][3000];
long long dp[3000][3000];

long long calc(int l, int r, int p) {
    if (l > r) return 0;
    if (f[l][r] == 1) return dp[l][r];
    
    f[l][r] = 1;
    
    if (p == 0) {
        return dp[l][r] = max(a[l] + calc(l + 1, r, 1), a[r] + calc(l, r - 1, 1));
    } else {
        return dp[l][r] = min(calc(l + 1, r, 0) - a[l], calc(l, r - 1, 0) - a[r]);
    }
}

int main() {
    int n, i;
    
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    
    printf("%lld\n", calc(0, n - 1, 0));
    
    return 0;
}
