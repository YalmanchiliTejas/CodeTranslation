#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (int) 1e9 + 7;

int add(int a, int b) {
        a += b;
        if (a >= MOD) {
                return a - MOD;
        }
        if (a < 0) {
                return a + MOD;
        }
        return a;
}

int mul(int a, int b) {
        return a * (ll) b % MOD;
}

int expow(int a, int b) {
        int r = 1;
        while (b) {
                if (b & 1) {
                        r = mul(r, a);
                }
                a = mul(a, a);
                b >>= 1;
        }
        return r;
}

int get_factorial(int i) {
        if (i == 0) {
                return 1;
        } else {
                return mul(get_factorial(i - 1), i);
        }
}

int inv(int x) {
        return expow(x, MOD - 2);
}

int comb(int n, int k) {
        int x = get_factorial(n), y = inv(mul(get_factorial(k), get_factorial(n - k)));
        return mul(x, y);
}

int sqr(int x) {
        return mul(x, x);
}

int n, m, k;

int main() {
        cin >> n >> m >> k;
        int a = comb(n * m - 2, k - 2), b = 0;

        for (int dr = 1; dr < n; dr++) {
                int pick = n - dr;
                b = add(b, mul(dr, mul(pick, sqr(m))));
        }
        for (int dc = 1; dc < m; dc++) {
                int pick = m - dc;
                b = add(b, mul(dc, mul(pick, sqr(n))));
        }

        cout << mul(a, b) << "\n";

        return 0;
}
