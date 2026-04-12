#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int64_t GetLayer(int64_t n) {
    return std::pow(2, n + 2) - 3;
}

int64_t GetPatty(int64_t n) {
    return std::pow(2, n + 1) - 1;
}

int64_t solve(int64_t n, int64_t x) {
    if (n == 0) {
        return (x > 0) ? 1 : 0;
    } else if (x == 1)
        return 0;
    else if (x <= GetLayer(n - 1) + 1) {
        return solve(n - 1, x - 1);
    } else if (x == 2 + GetLayer(n - 1)) {
        return GetPatty(n - 1) + 1;
    } else if (2 + GetLayer(n - 1) < x && x <= GetLayer(n - 1) * 2 + 2) {
        return GetPatty(n - 1) + 1 + solve(n - 1, x - 2 - GetLayer(n - 1));
    } else if (x = 3 + 2 * GetLayer(n - 1)) {
        return GetPatty(n - 1) * 2 + 1;
    }
}

int main(void) {
    cout << std::fixed << std::setprecision(10);
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int64_t n;
    int64_t x;
    cin >> n >> x;
    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }
    cout << solve(n, x) << endl;

    return 0;
}
