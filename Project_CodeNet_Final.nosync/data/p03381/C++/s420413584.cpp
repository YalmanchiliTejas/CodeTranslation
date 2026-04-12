
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long n;
    cin >> n;

    long x[n];
    long x_copy[n];

    for (long i = 0; i < n; i++) {
        cin >> x[i];
        x_copy[i] = x[i];
    }
    sort(x_copy, x_copy + n);
    long small_mean = x_copy[n / 2 - 1];
    long large_mean = x_copy[n / 2 ];

    for (long i = 0; i < n; i ++) {
        if (x[i] <= small_mean) {
            cout << large_mean << "\n";
        } else {
            cout << small_mean << "\n";
        }
    }

    return 0;
}
