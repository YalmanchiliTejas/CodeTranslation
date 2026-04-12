#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;

class Solution {
public:
    long long solve(long long n, long long m, long long K) {
        long long N = n * m;
        init(N + 123);

        long long P = nCr(N - 2, K - 2);
        long long res = 0;
        for (int i = 1; i <= n - 1; ++i) {
            res += i * ((n - i) * 1LL * m % MOD * m % MOD) % MOD;
            res %= MOD;
        }

        for (int i = 1; i <= m - 1; ++i) {
            res += i * ((m - i) * 1LL * n % MOD * n % MOD) % MOD;
            res %= MOD;
        }
        (res *= P) %= MOD;

        return res;
    }

private:
    const static long long MOD = 1000000007;

    vector<long long> pow2;
    vector<long long> F;
    vector<long long> IF;

    long long norm(long long a) {
        a %= MOD;
        if (a < 0) {
            a += MOD;
        }
        return a;
    }

    long long inverse(long long a) {
        long long b = MOD;
        long long u = 0, v = 1;
        a = norm(a);
        while (a != 0) {
            long long d = b / a;
            b -= d * a;
            u -= d * v;
            swap(a, b);
            swap(u, v);
        }
        return norm(u);
    }

    long long powM(long long x, long long e) {
        long long res = 1;
        while (e > 0) {
            if (e & 1) {
                res = res * x % MOD;
            }
            x = x * x % MOD;
            e >>= 1;
        }
        return res;
    }

    void init(int n) {
        F.clear();
        F.resize(n + 1, 1);
        IF = F;
        pow2.clear();
        pow2.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            pow2[i] = pow2[i - 1] * 2 % MOD;
        }

        for (int i = 1; i <= n; ++i) {
            F[i] = F[i - 1] * i % MOD;
        }
        IF[n] = inverse(F[n]);
        for (int i = n - 1; i > 0; --i) {
            IF[i] = IF[i + 1] * (i + 1) % MOD;
        }
    }

    long long nCr(int n, int r) {
        if (r < 0 || r > n) {
            return 0;
        }
        long long res = F[n] * IF[r] % MOD * IF[n - r] % MOD;
        return res;
    }

};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, m, k;
    cin >> n >> m >> k;
    Solution sol;
    cout << sol.solve(n, m, k) << "\n";

    return 0;
}