#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAX = 210000;
const int MOD = 1000000007;

typedef pair<long long, long long> pll;
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int N;
vector<long long> H;

// first: all, second: oxoxoxoxox
pll rec(int left, int right) {
    long long resall = 0, resalt = 0;

    // height
    long long height = 1LL<<60;
    for (int i = left; i < right; ++i) if (H[i] < height) height = H[i];
    for (int i = left; i < right; ++i) H[i] -= height;
    vector<pll> subs;
    int nleft = left;
    int width = 0;
    for (int i = left; i < right; ++i) {
        if (H[i] == 0) {
            if (i > nleft) subs.push_back(rec(nleft, i));
            nleft = i+1;
            ++width;
        }
    }
    if (right > nleft) subs.push_back(rec(nleft, right));
    
    // second -> second
    long long facalt = 1;
    for (auto p : subs) facalt *= p.second, facalt %= MOD;
    resalt += facalt * modpow(2LL, height, MOD) % MOD;
    resall += resalt;

    // first (not second)
    long long fac = 1;
    for (auto p : subs) {
        fac *= (p.first + p.second); fac %= MOD;
    }
    resall += fac * modpow(2LL, width, MOD) % MOD;
    resall += MOD - facalt * 2 % MOD;

    // result
    return pll(resall % MOD, resalt % MOD);;
}

int main() {
    cin >> N;
    H.resize(N); for (int i = 0; i < N; ++i) cin >> H[i];
    pll res = rec(0, N);
    cout << res.first << endl;
}
