#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// ある2つの配置の差の絶対値が何回足されるか
// N x Mの内Kが埋まり、ある2つが含まれる組み合わせは
// (N x M - 2) C (K - 2) 通り
// さらに行の差と列の差を分けてついて考えると上記にさらにM^2, N^2をそれぞれかける
// 例えば行の差の組み合わせの総和を上にかけると行の分の総和になる

long long mPow(long long x, long long n, const long long MOD)
{
    long long ans = 1;
    while (n != 0) {
        if (n & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        n = n >> 1;
    }
    return ans;
}

long long mFact(const long long n, const long long MOD)
{
    long long fac = 1;
    for (long long i = 1; i <= n; ++i) {
        fac *= i;
        fac %= MOD;
    }
    return fac;
}

long long mComb(const long long n, long long r, const long long MOD)
{
    if (n < r || n < 0) return 0;
    if (r * 2 > n) r = n - r;

    return ((mFact(n, MOD) * mPow(mFact(r, MOD), MOD - 2, MOD) % MOD) * mPow(mFact(n - r, MOD), MOD - 2, MOD)) % MOD;
}

long long mRangeDiffSum(const long long n, const long long MOD)
{
    long long ans = 0;
    for (long long i = 1; i < n; ++i) {
        ans += i * (n - i) % MOD;
    }
    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    constexpr long long MOD = 1e9 + 7;

    int N, M, K;
    cin >> N >> M >> K;

    long long comb = mComb(N * M - 2, K - 2, MOD);
    long long x = ((mRangeDiffSum(N, MOD) * mPow(M, 2, MOD)) % MOD * comb) % MOD;
    long long y = ((mRangeDiffSum(M, MOD) * mPow(N, 2, MOD)) % MOD * comb) % MOD;
    cout << (x + y) % MOD << endl;

    return 0;
}
