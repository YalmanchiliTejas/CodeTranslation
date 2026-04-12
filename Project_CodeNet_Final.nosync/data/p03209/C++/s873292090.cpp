#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    long long x;
    cin >> n >> x;

    long long p[n+1], t[n+1];
    p[0] = t[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = 2 * p[i-1] + 1;
        t[i] = 2 * t[i-1] + 3;
    }

    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (x >= 2 * t[i] + 3) {
            ans += 2 * p[i] + 1;
            x -= 2 * t[i] + 3;
        } else if (x >= 2 * t[i] + 2) {
            ans += 2 * p[i] + 1;
            x -= 2 * t[i] + 2;
        } else if (x >= t[i] + 2) {
            ans += p[i] + 1;
            x -= t[i] + 2;
        } else if (x >= t[i] + 1) {
            ans += p[i];
            x -= t[i] + 1;
        } else if (x >= 1) {
            x -= 1;
        }
    }

    cout << ans << endl;

    return 0;
}