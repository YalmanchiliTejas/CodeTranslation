#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    sort(begin(a), end(a));
    if (n % 2 == 0) {
        long long ans = 0; {
            for (int i = 0; i < n / 2 - 1; i++) ans -= a[i] * 2;
            ans -= a[n / 2 - 1];
            ans += a[n / 2];
            for (int i = n / 2 + 1; i < n; i++) ans += a[i] * 2;
        }
        cout << ans << endl;
    } else {
        long long ans1 = 0; {
            for (int i = 0; i < n / 2 - 1; i++) ans1 -= a[i] * 2;
            ans1 -= a[n / 2 - 1];
            ans1 -= a[n / 2];
            for (int i = n / 2 + 1; i < n; i++) ans1 += a[i] * 2;
        }
        long long ans2 = 0; {
            for (int i = 0; i < n / 2; i++) ans2 -= a[i] * 2;
            ans2 += a[n / 2];
            ans2 += a[n / 2 + 1];
            for (int i = n / 2 + 2; i < n; i++) ans2 += a[i] * 2;
        }
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
