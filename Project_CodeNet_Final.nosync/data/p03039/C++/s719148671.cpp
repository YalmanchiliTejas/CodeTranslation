/* ---------- STL Libraries ---------- */
// IO library
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>

// algorithm library
#include <algorithm>
#include <cmath>
#include <numeric>
#include <random>
#include <cstring>

// container library
#include <array>
#include <bitset>
#include <deque>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>
#include <stack>

/* ---------- Namespace ---------- */
using namespace std;

/* ---------- Type ---------- */
using ll = long long;
#define int ll
#define P pair<ll, ll>

/* ---------- Constants  */
const double PI = 3.141592653589793238462643383279;
const ll MOD = 1e9 + 7;
const int INF = 1LL << 55;

/* v-v-v-v-v-v-v-v-v Main Part v-v-v-v-v-v-v-v-v */
class Combination {
    int powmod(int a, int p) {
        int ans = 1;
        int mul = a;

        for (; p > 0; p >>= 1, mul = (mul * mul) % mod) {
            if ((p & 1) == 1) ans = (ans * mul) % mod;
        }

        return ans;
    }
public:
    int N;
    int mod;
    vector<int> fact;
    vector<int> revFact;

    Combination(int n, int m) : N(n), mod(m), fact(n+1), revFact(n+1) {
        fact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = fact[i-1] * i;
            fact[i] %= mod;
        }

        // Fermat's little theorem
        revFact[N] = powmod(fact[N], mod - 2);

        for (int i = N-1; i >= 0; i--) {
            revFact[i] = revFact[i+1] * (i+1);
            revFact[i] %= mod;
        }
    }

    int get(int a, int b) {
        if (a < 0 || b < 0) return 0;
        if (b > a) return 0;
        return (((fact[a] * revFact[b]) % mod) * revFact[a-b]) % mod;
    }
};

signed main() {
    int N, M, K;
    cin >> N >> M >> K;

    Combination comb = Combination(N * M, MOD);

    int ret = 0;
    for (int d = 1; d <= M - 1; d++) {
        ret += ((((((M - d) * N) % MOD) * N) % MOD) * d) % MOD;
        ret %= MOD;
    }
    for (int d = 1; d <= N - 1; d++) {
        ret += ((((((N - d) * M) % MOD) * M) % MOD) * d) % MOD;
        ret %= MOD;
    }
    ret *= comb.get(N * M - 2, K - 2);
    ret %= MOD;

    cout << ret << endl;
    return 0;
}