#include <iostream>
using namespace std;

int64_t countP[51], length[51];

int64_t solve(int64_t n, int64_t x) {
    if (x == 0) return 0;
    if (n == 0) return 1;
    if (length[n] == x) return countP[n];

    // x - 1
    int64_t ans = 0;
    if (x <= 1 + length[n - 1]) {
        ans += solve(n - 1, x - 1);
    } else {
        ans += solve(n - 1, length[n - 1]) + 1;
        // x - 2
        ans += solve(n - 1, x - 2 - length[n - 1]);
    }
    return ans;
}

int main() {
    int64_t n, x;
    cin >> n >> x;

    countP[0] = 1;
    length[0] = 1;

    for (int i = 1; i <= n; i++) {
        countP[i] = 1 + countP[i - 1] * 2;
        length[i] = 3 + length[i - 1] * 2;
    }

    cout << solve(n, x) << endl;

    return 0;
}