#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int P = 1000000007;
int n, i, a[200005];
i64 tot, ans;
int main() {
    scanf("%d", &n);
    for (i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for (i = n; i > 0; --i) {
        ans = (ans + tot * a[i]) % P;
        tot = (tot + a[i]) % P;
    }
    printf("%lld", ans);
}