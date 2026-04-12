#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9 + 7;

int64_t solve1(int n, vector<int64_t> a) {
    int64_t res = 0;
    vector<int64_t> csum(n + 1, 0);
    csum[0] = 0;
    for (size_t i = 0; i < n; i++) {
        csum[i + 1] = csum[i] + a[i];
    }
    for (size_t i = 0; i < n; i++) {
        int64_t sum = (csum[n] - csum[i + 1]) % mod;
        res += a[i] * sum;
        res %= mod;
    }
    return res;
}

int64_t solve2(int n, vector<int64_t> a) {
    int64_t res = 0;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            res += a[i] * a[j];
            res %= mod;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (auto &i : a) cin >> i;
    // printf("solve1: %lld\nsolve2: %lld\n", solve1(n, a), solve2(n, a));
    cout << solve1(n, a) << endl;
}
