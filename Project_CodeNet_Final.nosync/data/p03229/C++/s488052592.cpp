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
    for (int i = 0; i < n; i++) ans += abs(a[i] - a[n / 2]) * 2;
    if (n & 1) ans -= min(a[n / 2 + 1] - a[n / 2], a[n / 2] - a[n / 2 - 1]);
    else ans -= a[n / 2] - a[n / 2 - 1];
    cout << ans << endl;
    return 0;
}
