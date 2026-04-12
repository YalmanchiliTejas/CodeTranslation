
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int b[n];
    int mid;
    if (n % 2 == 1) {
        mid= (n + 1) / 2 - 1;
        b[0] = a[mid];
        if (a[mid] - a[mid - 1] < a[mid + 1] - a[mid]) {
            for (int i = 0; i < mid; ++i) {
                b[(i + 1) * 2] = a[i];
                b[i * 2 + 1] = a[n - 1 - i];
            }
        } else {
            for (int i = 0; i < mid; ++i) {
                b[(i + 1) * 2] = a[n - 1 - i];
                b[i * 2 + 1] = a[i];
            }
        }
    } else {
        mid= n / 2;
        for (int i = 0; i < mid; ++i) {
            b[i * 2 + 1] = a[i];
            b[i * 2] = a[mid + i];
        }
    }

    long long sum = 0;
    for (int i = 1; i < n; ++i) {
        sum += (long long)abs(b[i - 1] - b[i]);
    }

    cout << sum << '\n';

    return 0;
}
