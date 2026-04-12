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
std::array<std::array<lli, N + 1>, 2> A;

struct faster{
    lli Power[N+1], invP[N+1];
    constexpr faster(): Power(), invP(){
        Power[0] = 1;
        for(int i = 1; i <= N; ++i) Power[i] = (Power[i-1] * i) % mod;
        invP[N] = inverse(Power[N]);
        for(int i = N; i > 0; --i) invP[i-1] = (invP[i] * i) % mod;
    }
    constexpr void swap(lli &a, lli &b) const {
        a ^= b; b ^= a; a ^= b;
    }
    constexpr lli inverse(lli a) const noexcept{
        lli b = mod, u = 1, v = 0;
        while (b != 0) { 
            lli t = a / b; a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        u %= mod; if (u < 0) u += mod;
        return u;
    }
};

// 累乗の余りを求める関数
inline lli power(lli a, int n, lli mod_number___ = mod){
    lli res = 1, waiting = a;
    while(n){ if(n & 1){ 
        (res *= waiting) %= mod_number___;}
        (waiting *= waiting) %= mod_number___; 
        n >>= 1;
    }
    return res;
}

/* n人でp人グループを k 個作る分け方は
    nCpk * pkCp * (k-1)pCp * ... * pCp / k!
    = {n!/(n-pk)!pk!} * {pk!/(k-1)p!p!} * {(p-1)k!/(k-2)p!p!} * ... * pCp / k!
    = {n!/(n-pk)!pk!} * pk! / (p!)^k / k!
    = n! / { (n - pk)! * (p!)^k * k! }
*/

constexpr faster Init;

int main(void){
    int n, a, b, c, d; scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);

    A[0][0] = 1;
    for(int p = a; p <= b; ++p){
        for(int j = 0; j <= n; ++j) A[1][j] = A[0][j];
        for(int j = 0; j <= n; ++j){
            lli C = power(Init.invP[p], c) * Init.invP[j] % mod;
            int ptr = j + c * p; 
            // j + kp ≤ n <=> kp ≤ (n - j)
            int e = (n - j) / p; if(e > d) e = d;
            for(int k = c; k <= e; ++k, ptr += p){
                lli c = (Init.Power[ptr] * Init.invP[k] % mod) * C % mod;
                (A[1][ptr] += c * A[0][j]) %= mod;
                (C *= Init.invP[p]) %= mod;
            }
        }
        std::swap(A[0], A[1]);
    }
    printf("%lld\n", A[0][n]);
    return 0;
}