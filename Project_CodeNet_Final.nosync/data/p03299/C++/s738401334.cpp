#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath> // 変数名にy1が使えなくなるかも…。
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <string>

typedef __int128_t int128_t;
std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
    long long tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (long long)value;
    return output;
}

int128_t cal_mod(const int128_t n, const int128_t mod) {
    // n % modを計算する。ただしmod <= 0 ならば何もしない。nが負の場合、正にして補正する。
    if (mod <= 0) {
        return n;
    } else if (0 <= n) {
        return n % mod;
    } else {
        int128_t tmp = (-n) / mod + 1;
        return (n + tmp * mod) % mod;
    }
}

int128_t pow_mod(int128_t x, int128_t n, const int128_t mod) {
    // 累乗の計算。mod <= 0ならば余りの計算は行わない。
    int128_t ret = 1;
    while (n > 0) {
        if (n & 1) { ret = cal_mod(ret * x, mod); }
        x = cal_mod(x * x, mod);
        n = (n >> 1);
    }
    return ret;
}

const int128_t MOD = 1e9 + 7;
const int MAX_H = 1e9 + 7;
const int MAX_N = 110;
int N;
int128_t h[MAX_N];

int128_t s[MAX_N]; // s[i]:i番目に低い山（高さ2以上）の高さ。
std::map<int128_t, int> mp; // 2以上の高さに対して、何番目に低いか。

int128_t dp[MAX_N][MAX_N] = {};
// dp[i][j] : i番目の列まで塗終わり、その列で最初に現れる連続同色がs[j]の高さに収まる(s[j-1]には収まらない)塗り方の数。
// dp[i][0] は、連続同色が現れない塗り方。

int128_t calc_sub(int128_t h1, int128_t h2) {
    // h1まで交互に塗った1つの塗り方に対して、h2までに連続塗りを含む塗り方がいくつあるか。
    return cal_mod(pow_mod(2, h2 - h1, MOD) - 1, MOD);
}

int main(int argc, char **argv) {
    std::cin >> N;
    
    for (int i = 1; i <= N; i++) {
        std::cin >> h[i];
    }

    for (int i = 1; i <= N; i++) {
        if (1 < h[i]) {
            mp[h[i]] = 1;
        }
    }
    int cnt = 1;
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        mp[itr->first] = cnt;
        s[cnt] = itr->first;
        cnt++;
    }
    s[0] = 1;
    s[cnt] = MAX_H;
    dp[0][0] = 1;

    //std::cout << "check:" << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << std::endl;

    for (int i = 1; i <= N; i++) {
        if (h[i] == 1) {
            for (int j = 0; j < cnt; j++) {
                dp[i][0] = (dp[i][0] + dp[i-1][j] * 2) % MOD;
            }
        } else if (i == 1 || h[i-1] == 1) {
            dp[i][0] = (dp[i-1][0] * 2) % MOD;
            for (int j = 1; s[j] <= h[i]; j++) {
                dp[i][j] = (dp[i-1][0] * 2 * calc_sub(s[j-1], s[j]) * pow_mod(2, h[i] - s[j], MOD)) % MOD;
            }
        } else {
            dp[i][0] = (dp[i-1][0] * 2) % MOD;
            if (h[i] <= h[i-1]) {
                for (int j = 1; s[j] <= h[i-1]; j++) {
                    if (s[j] <= h[i]) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][0] = (dp[i][0] + dp[i-1][j] * 2) % MOD;
                    }
                }
            } else {
                for (int j = 1; s[j] <= h[i]; j++) {
                    if (s[j] <= h[i-1]) {
                        dp[i][j] = (dp[i-1][j] * pow_mod(2, h[i] - h[i-1], MOD)) % MOD;
                    } else {
                        dp[i][j] = (dp[i-1][0] * 2 * calc_sub(s[j-1], s[j]) * pow_mod(2, h[i] - s[j], MOD)) % MOD;
                    }
                }
            }
        }
        //std::cout << "dp:" << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << std::endl;
    }

    int128_t ret = 0;
    for (int j = 0; s[j] <= h[N]; j++) {
        ret = (ret + dp[N][j]) % MOD;
    }
    std::cout << ret << std::endl;
    
    return 0;
}