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
#include <map>
#include <unordered_map>
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
    std::vector<long long> factorial, factorial_inv, inv;
    Combi_Num() {}
    Combi_Num(const int n, const long long mod_num_in) {
        mod_num = mod_num_in;
        factorial.resize(n+1, 0);
        factorial_inv.resize(n+1, 0);
        inv.resize(n+1, 0);
        factorial[0] = 1;
        factorial_inv[0] = 1;
        inv[0] = 1;
        for (int i = 1; i <= n; i++) {
            factorial[i] = (factorial[i-1] * i) % mod_num;
            inv[i] = pow_mod(i, mod_num - 2, mod_num);
            factorial_inv[i] = (factorial_inv[i-1] * inv[i]) % mod_num;
        }
    }

    long long combi(const int n, const int r) {
        return (factorial[n] * ((factorial_inv[r] * factorial_inv[n-r]) % mod_num)) % mod_num;
    }

    long long perm(const int n, const int r) {
        return (factorial[n] * factorial_inv[n-r]) % mod_num;
    }
};

const long long MOD = 1000000007;
const int MAX_NM = 200050;
int N, M, K;

Combi_Num combi_num = Combi_Num(MAX_NM, MOD);

int main(int argc, char **argv) {
    std::cin >> N >> M >> K;

    long long ret = 0;

    for (int d = 1; d <= N - 1; d++) {
        long long pat = (N - d) * M * M;
        pat = pat % MOD;
        pat = (pat * combi_num.combi(N*M - 2, K - 2)) % MOD;
        ret = ret + (d * pat) % MOD;
        ret = ret % MOD;
    }

    for (int d = 1; d <= M - 1; d++) {
        long long pat = (M - d) * N * N;
        pat = pat % MOD;
        pat = (pat * combi_num.combi(N*M - 2, K - 2)) % MOD;
        ret = ret + (d * pat) % MOD;
        ret = ret % MOD;
    }

    std::cout << ret << std::endl;

    return 0;
}