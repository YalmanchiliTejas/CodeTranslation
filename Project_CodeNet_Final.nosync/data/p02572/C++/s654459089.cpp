#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, s, i, x;
    long long ans = 0;

    cin >> n >> s;
    for (i = 1; i < n; i++) {
        cin >> x;
        ans += (long long)x * (long long)s % MOD;
        s += x;
        if (s >= MOD) s-= MOD;
    }
    cout << ans % MOD<< "\n";
    return 0;
}
