#include <bits/stdc++.h>

using ll = long long;

ll solve(int n, ll x) {
    x = std::min(x, (1ll << (n + 2)) - 3);
    if (x == 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    if (x < (1ll << (n + 1)) - 1) {
        return solve(n - 1, x - 1);
    }
    return (1ll << n) + solve(n - 1, x - (1ll << (n + 1)) + 1);
}

int main() {
    int n;
    ll x;
    scanf("%d%lld", &n, &x);
    printf("%lld\n", solve(n, x));
    return 0;
}