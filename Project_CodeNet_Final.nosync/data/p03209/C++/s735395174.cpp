// Author: Shusuke Ueda
// AtCoder Beginner Contest 115 - Problem D

#include <iostream>
#include <vector>
using lint = int_fast64_t;

int main() {
    int n;
    lint x;
    std::cin >> n >> x;
    x--;

    std::vector<lint> patty(n + 1), length(n + 1);
    patty[0] = 1;
    length[0] = 1;
    for (int i = 1; i <= n; i++) {
        patty[i] = patty[i - 1] * 2 + 1;
        length[i] = length[i - 1] * 2 + 3;
    }

    lint ans = 0;
    auto count = [&](auto count_, int lev, lint pos) -> void {
        if (pos == 0) {
            if (lev == 0) {
                ans++;
            }
            return;
        } else if (pos < length[lev] / 2) {
            count_(count_, lev - 1, pos - 1);
        } else if (pos == length[lev] / 2) {
            ans += patty[lev - 1] + 1;
            return;
        } else if (pos < length[lev] - 1) {
            ans += patty[lev - 1] + 1;
            count_(count_, lev - 1, pos - length[lev] / 2 - 1);
        } else {
            ans += patty[lev];
            return;
        }
    };
    count(count, n, x);

    std::cout << ans << std::endl;
    
    return 0;
}