#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const int MOD = 1000000007;
#define MAX_N 1010

class NumberOfCase {
    public:
        // 初期化 O(n log m) m は素数
        // n : 求めたい組み合わせの最大値, m : 剰余(素数)
        NumberOfCase(ll n, ll m) : m_Size(n), m_Mod(m) {
            m_Fact = new ll[m_Size + 1];
            m_FInv = new ll[m_Size + 1];
            m_Inv = new ll[m_Size + 1];
            // 0! ～ m_Size! までの階乗を保管する配列の作成 (mod m_Mod をとってある)
            m_Fact[0] = 1;
            for(int i = 1; i <= m_Size; ++i) { m_Fact[i] = (m_Fact[i-1] * i) % m_Mod; }
            // m_Size! の逆元 1/m_Size! を二分累乗法で求める
            // フェルマーの小定理より a^-1 = a^(p-2) mod p -> (m_Size!)^-1 = (m_Size!)^(p-2) mod p
            m_FInv[m_Size] = ModPow(m_Fact[m_Size], m_Mod-2, m_Mod);
            // 以下 1 / (N-1)! = N / N! であることを利用
            for(int i = m_Size - 1; i >= 0; --i) { m_FInv[i] = (m_FInv[i + 1] * (i + 1)) % m_Mod; }
            // 逆元の作成（割り算のとき利用）
            m_Inv[1] = 1;
            for(int i = 2; i <= m_Size; ++i) { m_Inv[i] = m_Inv[m_Mod % i] * (m_Mod - m_Mod / i) % m_Mod; }
        }
        ~NumberOfCase() {
            delete[] m_Fact;
            delete[] m_FInv;
            delete[] m_Inv;
        }
        // 階乗 n! の取得 O(1)
        ll Factorial(ll n) { return m_Fact[n]; }
        // n! の逆元の取得 O(1)
        ll FInverse(ll n) { return m_FInv[n]; }
        // 逆元の取得 O(1)
        ll Inverse(ll n) { return m_Inv[n]; }
        // 剰余を考慮した割り算 n / m の結果を返す
        ll Div(ll n, ll m) { return (n * m_Inv[m]) % m_Mod; }
        // 順列 nPr の取得 O(1)
        ll Permutation(ll n, ll r) { return (m_Fact[n] * m_FInv[n - r]) % m_Mod; }
        // 組み合わせ nCr の取得 O(1)
        ll Combination(ll n, ll r) {
            ll ret = (m_Fact[n] * m_FInv[n - r]) % m_Mod;
            ret = (ret * m_FInv[r]) % m_Mod;
            return ret;
        }
        // 重複組み合わせ nHr の取得 O(1)
        ll Homogen(ll n, ll r) { return Combination(r+n-1, r); }
    private:
        // x の n 乗 を m で余りをとったもの O(log n)
        ll ModPow(ll x, ll n, ll mod) {
            ll res = 1;
            while ( n > 0) {
                if (n & 1) { res = res * x % mod; } // 最下位ビットが立っているときに x^(2^i) を掛ける
                x = x * x % mod;                    // x を順次 2 乗していく
                n >>= 1;
            }
            return res;
        }
    private:
        const ll    m_Size;     // 導出する範囲 (10^5 くらいまでにして欲しい)
        const ll    m_Mod;      // 剰余
        ll*         m_Fact;     // 階乗
        ll*         m_FInv;     // 階乗の逆元
        ll*         m_Inv;      // 逆元
};

ll N, A, B, C, D;
ll dp[MAX_N][MAX_N] = {};

signed main()
{
    cin >> N >> A >> B >> C >> D;
    NumberOfCase noc(N, MOD);
    REP(i, MAX_N) { dp[i][0] = 1; }

    for(int i = A; i <= B; ++i) {
        for(int j = 0; j <= N; ++j) {
            // i 人のグループを 1 つも作らない場合
            if(j != 0) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }

            ll pat = 1;
            for(int k = 1; k <= D && j + i * k <= N; ++k) {
                pat = (pat * noc.Combination(N - j - i * (k - 1), i)) % MOD;
                pat = noc.Div(pat, k);
                if(k >= C) {
                    dp[i+1][j+i*k] += (dp[i][j] * pat) % MOD;
                    dp[i+1][j+i*k] %= MOD;
                }
            }
        }
    }
    printf("%lld\n", dp[B+1][N]);
    return 0;
}
