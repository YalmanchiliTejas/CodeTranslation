#include <bits/stdc++.h>
using namespace std;
using lint     = long long;
const lint inf = 1LL << 60;
const lint mod = 1000000007;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    lint n, k;
    cin >> n >> k;
    lint ret = 0;
    for (int b = k + 1; b <= n; ++b) {
        lint temp = n / b;
        ret += temp * (b - k);
        lint rem = n % b;
        if (k != 0)
            ret += max(0LL, rem + 1 - k);
        else
            ret += max(0LL, rem - k);
    }
    cout << ret << "\n";
    return 0;
}