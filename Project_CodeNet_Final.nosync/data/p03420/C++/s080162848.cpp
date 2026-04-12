#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int64_t n, k;
    cin >> n >> k;

    int64_t r = n * n;
    if (k > 0) {
        for (int64_t b = 1; b <= n; b++) {
            int64_t x = (n + 1) / b;
            int64_t y = (n + 1) % b;
            int64_t t = x * min(k, b) + min(y, k);
            //if (b < 10) cout << b << ' ' << x << ' ' << y << endl;
            r -= t - 1;
        }
    }

    cout << r << endl;

    return 0;
}