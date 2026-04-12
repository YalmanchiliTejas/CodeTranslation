#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<P> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b.begin(), b.end());
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            ans[b[i].second] = b[n / 2].first;
        } else {
            ans[b[i].second] = b[n / 2 - 1].first;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}