#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

long long pow_mod(long long x, long long n, long long mod_num) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) { res = (res * x) % mod_num; }
        x = (x * x) % mod_num;
        n = (n >> 1);
    }
    return res;
}

class Combi_Num {
    public:
    long long mod_num;
    std::vector<long long> fac, den;
    Combi_Num() {}
    Combi_Num(const int n, const int mod_num_in) {
        mod_num = mod_num_in;
        fac.resize(n+1, 0);
        den.resize(n+1, 0);
        fac[0] = 1;
        den[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = (fac[i-1] * i) % mod_num;
            den[i] = (den[i-1] * pow_mod(i, mod_num - 2, mod_num)) % mod_num;
        }
    }

    long long calc(const int n, const int r) {
        return (fac[n] * ((den[r] * den[n-r]) % mod_num)) % mod_num;
    }

    //long long calc_inv(const int n, const int r) {
    //    return (den[n] * ((fac[r] * fac[n-r]) % mod_num)) % mod_num;
    //}
};

const int MAX_N = 1050;
const long long MOD = (long long)1000000007;

Combi_Num combi_num = Combi_Num(MAX_N * 10, MOD);

int N, A, B, C, D;

struct Sub_Pattern {
    long long num;
    long long pattern_num;
};

long long calc_sub_pattern_num(const long long i, const long long j) {
    long long ret = 1;
    for (long long n = i * j; n >= i; n -= i) {
        ret = (ret * combi_num.calc(n, i)) % MOD;
    }
    ret = (ret * combi_num.den[j]) % MOD;
    return ret;
}

std::vector<Sub_Pattern> sub_pattern[MAX_N];

long long dp[MAX_N][MAX_N] = {};

int main(int argc, char **argv) {
    std::cin >> N >> A >> B >> C >> D;
    
    //std::vector<long long> sub_group;
    for (int i = A; i <= B; i++) {
        Sub_Pattern sub;
        sub.num = 0;
        sub.pattern_num = 1;
        sub_pattern[i].push_back(sub);
        for (int j = C; j <= D; j++) {
            if (i * j <= N) {
                sub.num = j;
                sub.pattern_num = calc_sub_pattern_num(i, j);
                sub_pattern[i].push_back(sub);
            }
        }
    }

    //std::cout << calc_pattern(N, 1, 0) << std::endl;

    dp[A-1][0] = 1;
    for (int i = A; i <= B; i++) {
        for (auto sub : sub_pattern[i]) {
            for (int cn = 0; cn <= N; cn++) {
                if (cn + i * sub.num <= N) {
                    long long tmp = dp[i-1][cn];
                    tmp = (tmp * combi_num.calc(N - cn, i * sub.num)) % MOD;
                    tmp = (tmp * sub.pattern_num) % MOD;
                    dp[i][cn + i * sub.num] = (dp[i][cn + i * sub.num] + tmp) % MOD;
                }
            }
        }
    }

    std::cout << dp[B][N] << std::endl;

    return 0;
}