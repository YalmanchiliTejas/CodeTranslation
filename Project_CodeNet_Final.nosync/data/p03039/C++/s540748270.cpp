#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 0
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 200010

class NumberOfCase {
    public:
        // 初期化 O(n log m) m は素数
        // n : 求めたい組み合わせの最大値, m : 剰余(素数)
        NumberOfCase(ll n, ll m) : m_Size(n), m_Mod(m) {
            m_Fact.resize(m_Size + 1);
            m_FInv.resize(m_Size + 1);
            m_Inv.resize(m_Size + 1);
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
        vector<ll>  m_Fact;     // 階乗
        vector<ll>  m_FInv;     // 階乗の逆元
        vector<ll>  m_Inv;      // 逆元
};

ll N, M, K;

signed main()
{
    cin >> N >> M >> K;
    NumberOfCase noc(MAX_N, MOD);
    ll ans = 0;

    // X 軸方向の距離を考える
    for(ll dx = 1; dx < M; ++dx) {
        // X の差が dx になる2点を選ぶパターン
        // (M - dx) * N^2
        ll cur = (M - dx);
        cur *= N;
        cur %= MOD;
        cur *= N;
        cur %= MOD;
        // このパターン数分だけ、距離 dx が出現する
        cur *= dx;
        cur %= MOD;
        // この 2 点以外の点の選択パターンは NM-2 C K-2
        cur *= noc.Combination(N * M - 2, K - 2);
        cur %= MOD;

        // これで X 方向で距離 dx になる全パターン分の和が出るので
        // 答えに加える
        ans += cur;
        ans %= MOD;
    }

    // 同様に Y 軸方向の距離を考える
    for(ll dy = 1; dy < N; ++dy) {
        ll cur = (N - dy);
        cur *= M;
        cur %= MOD;
        cur *= M;
        cur %= MOD;

        cur *= dy;
        cur %= MOD;

        cur *= noc.Combination(N * M - 2, K - 2);
        cur %= MOD;

        ans += cur;
        ans %= MOD;
    }

    printf("%lld\n", ans);

    return 0;
}
