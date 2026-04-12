#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

ll h[51] = {};
ll p[51] = {};

ll f(int n, ll x) {
    if (n == 0) {
        return 1;
    } else if (x <= 1) {
        return 0;
    } else if (x <= h[n - 1] + 1) {
        return f(n - 1, x - 1);
    } else if (x == h[n - 1] + 2) {
        return p[n - 1] + 1;
    } else if (x <= 2 * h[n - 1] + 2) {
        return f(n - 1, x - (h[n - 1] + 2)) + p[n - 1] + 1;
    } else {
        return 2 * p[n - 1] + 1;
    }
}

int main() {
    int N;
    ll X;
    cin >> N >> X;

    h[0] = 1, p[0] = 1;
    for (int i = 1; i <= N; i++) {
        h[i] = 2 * h[i - 1] + 3;
        p[i] = 2 * p[i - 1] + 1;
    }

    cout << f(N, X) << endl;
}