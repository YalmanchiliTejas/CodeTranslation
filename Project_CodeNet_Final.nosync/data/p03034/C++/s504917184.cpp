#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    long long ans = 0;
    for (int d = 1; d < n; d++) {
        long long cur = 0;
        for (int a = n - 1; a > d; a -= d) {
            cur += s[a] + s[n-1-a];
            if (!((n - 1) % d == 0 && (n - 1 - a) / d * 2 * d >= n - 1)) {
                ans = max(ans, cur);
            }
        }
    }

    cout << ans << endl;

    return 0;
}
