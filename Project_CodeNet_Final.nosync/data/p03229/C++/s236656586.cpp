#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int i = 0;
    int k;
    long ansA = 0;

    // a1 < a2 > a3 < a4 > ...

    // 係数 +2
    for (k = 1; k < n - 1; k += 2) {
        ansA += (2 * a[i++]);
    }

    // 係数 +1
    if (k == n - 1) {
        ansA += a[i++];
    }

    // 係数 -1
    ansA -= a[i++];
    if (n > 2 && ((n - 1) % 2 == 0)) {
        ansA -= a[i++];
    }

    // 係数 -2
    for (k = 2; k < n - 1; k += 2) {
        ansA -= (2 * a[i++]);
    }

    // a1 > a2 < a3 > a4 < ...
    long ansB = 0;
    i = 0;

    // 係数 +2
    for (k = 2; k < n - 1; k += 2) {
        ansB += (2 * a[i++]);
    }

    // 係数 +1
    ansB += a[i++];
    if (n > 2 && ((n - 1) % 2 == 0)) {
        ansB += a[i++];
    }

    // 係数 -1
    if (n % 2 == 0) {
        ansB -= a[i++];
    }

    // 係数 -2
    for (k = 1; k < n - 1; k += 2) {
        ansB -= (2 * a[i++]);
    }
    cout << max(ansA, ansB) << endl;

    return 0;
}
