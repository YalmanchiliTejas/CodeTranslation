#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, P = 1000000007;
int n, a[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    function<pair<int, int>(int, int, int)> solve = [&](int l, int r, int lst) {
        int x = *min_element(a + l, a + r + 1);
        int coef = 1, sum = 1, num = r - l + 1;
        for (int i = l, j; i <= r; i++) if (a[i] ^ x) {
            for (j = i; a[j] ^ x && j <= r; j++) num--;
            auto p = solve(i, j - 1, x); i = j;
            coef = 1LL * coef * p.first % P;
            sum = 1LL * sum * (p.first + p.second) % P;
        }
        return pair<int, int>(1LL * coef * qp(2, x - lst) % P,
            (1LL * sum * qp(2, num) + 1LL * coef * (qp(2, x - lst) - 2) % P) % P);
    };
    auto p = solve(1, n, 0);
    printf("%d\n", (p.second + P) % P);
    return 0;
}