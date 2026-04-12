#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    while (cin >> n >> l >> r, n | l | r) {
        int ans = 0;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int x = l; x <= r; x++) {
            int f = 1;
            for (int i = 0; i < n; i++) {
                if (x % a[i] == 0) {
                    f = 0;
                    if (i % 2 == 0) ans++;
                    break;
                }
            }
            if (f && n % 2 == 0) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
