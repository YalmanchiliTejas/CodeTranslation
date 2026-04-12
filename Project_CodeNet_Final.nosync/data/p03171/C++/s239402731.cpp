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
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
#define MAX_N 3010

template< typename T >
class CumulativeSum
{
public:
    CumulativeSum() {}
    CumulativeSum(int sz) : m_Data(sz, T(0)) {};

    void Init(int sz) { m_Data.assign(sz, T(0)); }

    // k に x を加える O(1)
    void Add(int k, T x) {
        assert(static_cast<int>(m_Data.size()) >= k);
        if(static_cast<int>(m_Data.size()) <= k) { m_Data.push_back(x); }
        else { m_Data[k] = (m_Data[k] + x); }
    }

    // 累積和の構築 O(m_Data.size())
    void Build() {
        for(int i = 1; i < static_cast<int>(m_Data.size()); i++) {
            m_Data[i] = (m_Data[i] + m_Data[i - 1]);
        }
    }

    // 区間 [0, k] の和を返す O(1)
    // 閉区間なので k が含まれることに注意
    T Query(int k) {
        if(k < 0) { return T(0); }
        return (m_Data[min(k, static_cast<int>(m_Data.size()) - 1)]);
    }

    // 区間 [l, h] の和を返す O(1)
    // 閉区間なので k が含まれることに注意
    T Query(int l, int h) {
        return (this->Query(h) - this->Query(l-1));
    }
private:
    vector< T > m_Data;
};

ll N;
vector<ll> A;
CumulativeSum<ll> cs;
ll dp[MAX_N][MAX_N][2];

enum Player { Taro = 0, Jiro = 1 };

// 左側は l 右側は r を見ていて、プレイヤーが player のときの
// 最大の X か Y の値
ll dfs(ll l, ll r, ll player) {
    if(l > r) { return 0; }
    ll next_player = (player == Taro) ? Jiro : Taro;

    ll& ret = dp[l][r][player];
    if(ret != LLINF) { return ret; }

    // 左側を取った場合
    ll next_player_point_1 = dfs(l+1, r, next_player);
    ll player_point_1 = cs.Query(l, r) - next_player_point_1;
    // 右側を取った場合
    ll next_player_point_2 = dfs(l, r-1, next_player);
    ll player_point_2 = cs.Query(l, r) - next_player_point_2;

    ret = max(player_point_1, player_point_2);

    return ret;
}

signed main()
{
    cin >> N;
    A.assign(N, 0);
    cs.Init(N);
    REP(i, N) {
        cin >> A[i];
        cs.Add(i, A[i]);
    }
    cs.Build();
    REP(i, N) { REP(j, N) { REP(k, 2) { dp[i][j][k] = LLINF; } } }
    ll X = dfs(0, N-1, Taro);
    ll Y = cs.Query(0, N-1) - X;
    printf("%lld\n", X - Y);
    return 0;
}
