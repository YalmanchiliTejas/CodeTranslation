#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
struct Edge {
    int to;
    int weight;
    Edge(int t, int w)
        : to(t)
        , weight(w)
    {
    }
};
using Graph = vector<vector<int>>;
using Graph_e = vector<vector<Edge>>;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

template <class T>
inline bool chmin(T& a, T b)
{
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T& a, T b)
{
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

// 負の数にも対応した % 演算
long long mod(long long val, long long m)
{
    long long res = val % m;
    if (res < 0)
        res += m;
    return res;
}

// a^n modを計算する
long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    // nを2進数表示して1が埋まっている桁に関してはa^mをかけていく
    while (n > 0) {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

// a^{-1} mod を計算する
long long modinv(long long a, long long mod)
{
    return modpow(a, mod - 2, mod);
}

int main()
{
    int N, M;
    cin >> N >> M;
    if (M == N)
        cout << "Yes" << endl;
    else {
        cout << "No" << endl;
    }
}