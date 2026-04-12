#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
// 1 <= a <= n
// 1 <= b <= n
// a % b >= K
// a - [a / b] * b >= K
// b
// [a / b]
// min(n, [a / b] * b + K) <= a < min(n, ([a / b] + 1) * b)
ll n, k, ans;

int main() {
    scanf("%lld%lld", &n, &k);
    if (k == 0) ans = n * n;
    else {
        for (ll b = k + 1; b <= n; b++) {
            ans += (n / b) * (b - k);
            if (n % b >= k) ans += n % b - k + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
