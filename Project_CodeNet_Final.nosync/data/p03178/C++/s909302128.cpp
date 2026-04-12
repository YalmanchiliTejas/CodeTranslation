#include <bits/stdc++.h>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using vec_i64 = vector<i64>;
using vvec_i64 = vector<vec_i64>;

int ctoi(const char c) {
    switch (c) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        default: return -1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    i64 const MOD = 1e9 + 7;

    string K;
    i32 D;
    cin >> K >> D;

    vector<i32> vec_K;
    i32 num_digits = K.size();
    for (int i = 0; i < num_digits; i++) {
        vec_K.emplace_back(ctoi(K.at(i)));
    }
    vvec_i64 dp(2, vec_i64(D, 0));
    dp.at(1).at(0) = 1;
    for (int i = 0; i < num_digits; i++) {
        i32 digit = vec_K.at(i);
        vvec_i64 next_dp(2, vec_i64(D, 0));
        for (int n = 0; n < 10; n++) {
            for (int d = 0; d < D; d++) {
                i32 next_reminder = (d + n) % D;
                if (n < digit) {
                    next_dp.at(0).at(next_reminder) += dp.at(0).at(d) + dp.at(1).at(d);
                }
                else if (n == digit) {
                    next_dp.at(0).at(next_reminder) += dp.at(0).at(d);
                    next_dp.at(1).at(next_reminder) += dp.at(1).at(d);
                }
                else {
                    next_dp.at(0).at(next_reminder) += dp.at(0).at(d);
                }
                next_dp.at(0).at(next_reminder) %= MOD;
                next_dp.at(1).at(next_reminder) %= MOD;
            }
        }
        dp = next_dp;
    }
    i64 res = (dp.at(0).at(0) + dp.at(1).at(0)) - 1;
    if (res < 0) {
        res += MOD;
    }
    cout << res << "\n";
}
