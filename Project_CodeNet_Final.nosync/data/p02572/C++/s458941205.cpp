#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    vector<int> suff_sums(n + 1);
    suff_sums[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        suff_sums[i] = suff_sums[i + 1] + v[i];
        suff_sums[i] = suff_sums[i] % 1'000'000'007;
    }
    int result = 0;
    for (int i = 0; i < n - 1; ++i) {
        result += v[i] * suff_sums[i + 1];
        result = result % 1'000'000'007;
    }
    cout << result;
    return 0;
}