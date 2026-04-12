#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;

const ll MOD = 1e9 + 7;
const int maxn = 2e5 + 5;
using namespace std;

ll a[maxn], n, sum[maxn], ans;

int main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        sum[i] = (a[i] + sum[i - 1]) % MOD;
    }

    for (int i = 2; i <= n; i++) {
        ans = (ans + a[i] * sum[i - 1] % MOD) % MOD;
    }
    printf("%lld\n", ans);
    return 0;
}