#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];

    reverse(a.begin(), a.end());
    vector<int> x;
    x.push_back(1e9 + 100);

    rep(i, 0, n) {
        int j = upper_bound(x.begin(), x.end(), a[i]) - x.begin();
        if (x[j] > 1e9) {
            x[j] = a[i];
            x.push_back(1e9 + 100);
        } else {
            x[j] = a[i];
        }
    }
    cout << x.size() - 1 << endl;

    return 0;
}
