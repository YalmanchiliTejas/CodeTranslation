#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i];
        d[i] /= 10;
    }
    int can1 = d[0];
    for (int i = 1; i < n; ++i) {
        if (d[i] > 0) {
            if (can1 < i) {
                cout << "no" << '\n';
                return 0;
            }
            can1 = max(can1, i + d[i]);
        } else {
            if (can1 <= i) {
                cout << "no" << '\n';
                return 0;
            }
        }
    }
    vector<int> dd(n);
    for (int i = 0; i < n; ++i) {
        dd[n - i - 1] = d[i];
    }
    int can2 = dd[0];
    for (int i = 1; i < n; ++i) {
        if (dd[i] > 0) {
            if (can2 < i) {
                cout << "no" << '\n';
                return 0;
            }
            can2 = max(can2, i + dd[i]);
        } else {
            if (can2 <= i) {
                cout << "no" << '\n';
                return 0;
            }
        }
    }
    cout << "yes" << '\n';
    return 0;
}
