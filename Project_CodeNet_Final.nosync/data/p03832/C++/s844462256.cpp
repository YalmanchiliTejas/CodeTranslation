#include <iostream>
#include <limits>
#include <cfenv>
#include <cmath>
#include <algorithm>
#include <array>
#include <bitset>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <tuple>
#include <queue>
#include <vector>
#include <cmath>
#include <random>
#include <math.h>
#include <list>
#include <random>
#include <functional>


#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define REP(i, n) FOR(i, 0, n)
#define rREP(i, n) for(int (i) = (n) - 1; (i) >= 0; --(i))
#define ALL(TheArray) TheArray.begin(), TheArray.end()

using lli = long long int;
using pii = std::pair<int, int>;

template <class T> inline bool chmax(T& a, T b){
    if(a < b){a = b; return true;}
    return false;
}
template <class T> inline bool chmin(T& a, T b){
    if(a > b){a = b; return true;}
    return false;
}


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


constexpr int N = 1000;
constexpr int mod = 1e9 + 7;
std::array<std::array<lli, N + 1>, N + 1> A;
std::array<lli, N+1> F, invF;

lli power(lli a, int n = mod - 2){
    if(n == 0) return 1;
    lli p = power(a * a % mod, n / 2);
    if(n & 1) return (p * a) % mod;
    return p;
}

/* n人でp人グループを k 個作る分け方は
    nCpk * pkCp * (k-1)pCp * ... * pCp / k!
    = {n!/(n-pk)!pk!} * {pk!/(k-1)p!p!} * {(p-1)k!/(k-2)p!p!} * ... * pCp / k!
    = {n!/(n-pk)!pk!} * pk! / (p!)^k / k!
    = n! / { (n - pk)! * (p!)^k * k! }
*/

int main(void){
    int n, a, b, c, d; scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    F[0] = 1; for(int x = 1; x <= n; ++x) F[x] = (F[x-1] * x) % mod;
    invF[n] = power(F[n]);
    for(int x = n; x > 0; --x) invF[x-1] = (invF[x] * x) % mod;

    int bMa = b - a;
    A[0][0] = 1;
    for(int i = 0; i <= bMa; ++i){
        int p = a + i;
        for(int j = 0; j <= n; ++j){
            (A[i+1][j] += A[i][j]) %= mod;

            for(int k = c; k <= d and j + k * p <= n; ++k){
                lli c = F[j + k * p] * invF[j] % mod; (c *= invF[k]) %= mod;
                (c *= power(power(F[p], k))) %= mod;
                (A[i + 1][j + k * p] += c * A[i][j]) %= mod;
            }
        }
    }

    printf("%lld\n", A[bMa+1][n]);
    return 0;
}