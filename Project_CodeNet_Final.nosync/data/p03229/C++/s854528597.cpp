#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &ai: a) cin >> ai;
    sort(begin(a), end(a));
    long long ans = 0;
    if (n % 2 == 0) {
        vector<int> b{1, -1};
        int m = n / 2 - 1;
        for (int i = 0; i < m; i++) b.emplace_back(2);
        for (int i = 0; i < m; i++) b.emplace_back(-2);
        sort(begin(b), end(b));
        for (int i = 0; i < n; i++) ans += a[i] * b[i];
    } else {
        vector<int> b{1, 1};
        int m = n / 2;
        for (int i = 1; i < m; i++) b.emplace_back(2);
        for (int i = 0; i < m; i++) b.emplace_back(-2);
        for (int k: {1, -1}) {
            for (int &bi: b) bi *= k;
            sort(begin(b), end(b));
            long long tmp = 0;
            for (int i = 0; i < n; i++) tmp += a[i] * b[i];
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return 0;
}
