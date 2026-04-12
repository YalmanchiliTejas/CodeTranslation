#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int64_t> a(n);
    for (auto &e : a) cin >> e;

    vector<int64_t> sum(n);
    sum.back() = a.back();
    for (int i = n - 2; 0 <= i; --i) {
        sum[i] = sum[i + 1] + a[i];
    }

    int64_t ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans = (ans + (sum[i + 1] % 1000000007) * (a[i] % 1000000007)) % 1000000007;
    }

    cout << ans << endl;
}

