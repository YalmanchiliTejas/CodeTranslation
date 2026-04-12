
#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>

using namespace std;

typedef long long LL;

#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define rep(i,n) for (int i = 0; i < (n); ++i)

const int MOD = 1000000007;


// ax + by = gcd(a, b) となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}


LL fact(int a)
{
    LL f = 1;
    for (int i = 1; i <= a; ++i) {
        f = (f * i) % MOD;
    }
    return f;
}

int choose(int a, int b) 
{
    LL fa = fact(a);
    LL i1 = modinv(fact(b), MOD);
    LL i2 = modinv(fact(a-b), MOD);
    return (fa * i1 % MOD) * i2 % MOD;
}

int main()
{
    LL N, M, K;
    cin >> N >> M >> K;
    
    LL dxSum = 0;
    for (int dx = 1; dx < M; ++dx) {
        dxSum = (dxSum + dx * (M-dx)) % MOD; 
    }
    dxSum = dxSum * (N * N % MOD) % MOD;

    LL dySum = 0;
    for (int dy = 1; dy < N; ++dy) {
        dySum = (dySum + dy * (N-dy)) % MOD; 
    }
    dySum = dySum * (M * M % MOD) % MOD;

    LL ans = choose(N*M-2, K-2) * ((dxSum + dySum) % MOD) % MOD;

    cout << ans << endl;

    return 0;
}
