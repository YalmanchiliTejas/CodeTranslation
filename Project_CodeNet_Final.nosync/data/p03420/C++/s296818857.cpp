#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 1 <= a <= n 
// a - [a / b] * b >= K

int main() {
    int n, K;
    scanf("%d%d", &n, &K);
    LL ret = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; j += i) {
            ret += min(j + i, n + 1) - min(min(j + i, n + 1), j + K);
        }
    }
    if (K == 0) ret -= n;
    return printf("%lld\n", ret), 0;
}