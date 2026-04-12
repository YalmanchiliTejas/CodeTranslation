#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define ALL(c) (c).begin(), (c).end()
const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    if (n % 2 == 0) {
        for (int i = 0; i < n / 2; i++) {
            cin >> a[n / 2 + i] >> a[n / 2 - 1 - i];
        }

    } else {
        cin >> a[n / 2];
        for (int i = 1; i <= n / 2; i++) {
            cin >> a[n / 2 + i] >> a[n / 2 - i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}
