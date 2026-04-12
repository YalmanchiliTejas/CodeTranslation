#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

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
const int MAX_N = 200010;

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

int N;
vector<int> A;

CumulativeSum<int> even, odd;

int Even() {
    int ret = even.Query(N-1);
    chmax(ret, odd.Query(N-1));
    REP(i, N-2) {
        int cand = even.Query(0, i) + odd.Query(i + 2, N-1);
        chmax(ret, cand);
    }
    return ret;
}

int dp[MAX_N][2][3];
// i 番目を見ていて、一つ前の値を取っているなら pre = 1
// 2 こ飛ばしを two 回使っている
int dfs(int i, int pre, int two) {
    if(i >= N) {
        return (two == 2) ? 0 : -INF;
    }
    int& ret = dp[i][pre][two];
    if(ret != -LLINF) { return ret; }

    if(pre == 0) {
        // 2 こ飛ばし
        if(i != N - 1 && two < 2) {
            chmax(ret, dfs(i+1, 0, two + 1));
        }
        chmax(ret, dfs(i+1, 1, two) + A[i]);
    }
    else {
        chmax(ret, dfs(i+1, 0, two));
    }
    return ret;
}

int Odd() {
    // 0 と N-1 を取らない
    int ret = odd.Query(N-1);
    chmax(ret, even.Query(N-2));
    // 0 を取って N-1 を取らない
    REP(i, N-2) {
        int cand = even.Query(0, i) + odd.Query(i + 2, N-1);
        chmax(ret, cand);
    }
    // N-1 を取って 0 を取らない
    REP(i, N-2) {
        int cand = odd.Query(0, i) + even.Query(i + 2, N-1);
        chmax(ret, cand);
    }
    // 0 と N-1 を取る
    REP(i, N) {
        if(i % 2 != 0 ) { continue; }
        int cand = even.Query(N-1) - A[i];
        chmax(ret, cand);
    }
    REP(i, MAX_N) {
        REP(j, 2) {
            REP(k, 3) {
                dp[i][j][k] = -LLINF;
            }
        }
    }
    int cand = dfs(1, 1, 0) + A[0];
    chmax(ret, cand);
    return ret;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }

    even.Init(N);
    odd.Init(N);
    REP(i, N) {
        if(i % 2 == 0) {
            even.Add(i, A[i]);
        }
        else {
            odd.Add(i, A[i]);
        }
    }
    even.Build();
    odd.Build();

    int ans = 0;
    if(N % 2 == 0) {
        ans = Even();
    }
    else {
        ans = Odd();
    }
    printf("%lld\n", ans);

    return 0;
}
