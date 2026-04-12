#include <bits/stdc++.h>
using namespace std;

long b[51];
long p[51];

long f(int n, long x) {
    if (n == 0) {
        return (x > 0 ? 1 : 0);
    }

    if (x < (b[n - 1] + p[n - 1]) + 2) {
        return f(n - 1, x - 1);
    } else if (x > b[n - 1] + p[n - 1] + 2) {
        return p[n - 1] + 1 + f(n - 1, x - 2 - (b[n - 1] + p[n - 1]));
    } else {
        return p[n - 1] + 1;
    }
}

int main() {
    int n;
    long x;

    cin >> n >> x;

    b[0] = 0;
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] * 2 + 2;
        p[i] = p[i - 1] * 2 + 1;
    }

    cout << f(n, x) << endl;

    return 0;
}
