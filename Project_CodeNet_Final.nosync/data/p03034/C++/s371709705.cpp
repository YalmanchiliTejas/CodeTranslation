#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> as(n);
    for (int i = 0; i < n; i++) cin >> as[i];

    long long ans = 0;
    for (int i = 1; i < n; i++) {
        long long tmp = 0;
        if ((n - 1) % i == 0) {
            for (int j = 0, k = n - 1; j < k; j += i, k -= i) {
                tmp += as[j] + as[k];
                ans = max(ans, tmp);
            }
        } else {
            for (int j = 0, k = n - 1; j < n && k > i; j += i, k -= i) {
                tmp += as[j] + as[k];
                ans = max(ans, tmp);
            }
        }
    }
    cout << ans << endl;
}
