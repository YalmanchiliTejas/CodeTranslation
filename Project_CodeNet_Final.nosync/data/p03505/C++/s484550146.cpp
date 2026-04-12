#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    int64_t k, a, b;
    cin >> k >> a >> b;

    if (a >= k) {
        cout << 1 << endl;
        return 0;
    }

    k -= a;
    a -= b;
    if (a > 0) {
        cout << (k + a - 1) / a * 2 + 1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}