#include <bits/stdc++.h>


using namespace std;

long long a[3009], dp[3009][3009];
int main() {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld", a + i);
        for (int left = n; left >= 1; left--) {
                for (int right = left; right <= n; right++) {
                        //[left, right]
                        bool taro = (left - 1 + n - right) % 2 == 0;
                        if (taro) {
                                if (left == right) {
                                        dp[left][right] = a[left];
                                } else {
                                        dp[left][right] = max(dp[left + 1][right] + a[left], dp[left][right - 1] + a[right]);
                                }
                        } else {
                                if (left == right) {
                                        dp[left][right] = -a[left];
                                } else {
                                        dp[left][right] = min(dp[left + 1][right] - a[left], dp[left][right - 1] - a[right]);
                                }
                        }
                }
        }
        printf("%lld", dp[1][n]);
}