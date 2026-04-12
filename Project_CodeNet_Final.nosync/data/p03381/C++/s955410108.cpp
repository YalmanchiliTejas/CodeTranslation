#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    ll x[n], x_sorted[n];
    rep(i, n) cin >> x[i];
    copy(x, x + n, x_sorted);
    sort(x_sorted, x_sorted + n);

    ll l = x_sorted[n / 2 - 1];
    ll r = x_sorted[n / 2];

    rep(i, n) {
        if (x[i] <= l)
            cout << r << endl;
        else
            cout << l << endl;
    }

    return 0;
}
