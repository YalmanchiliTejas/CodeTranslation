#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

#define REP(i,n) for(int i=0;i<n;++i)
#define ALL(name) name.begin(),name.end()
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
#define MAX_N 100010

ll lis(const vector<ll>& v) {
    ll ret = 0;
    // 増加部分列の長さが i のとき、一番右に来る数字の最小値(dp 内の値は単調増加になる)
    vector<ll> dp(v.size(), LLINF);
    for(int i = 0; i < v.size(); ++i) {
        auto it = upper_bound(dp.begin(), dp.end(), v[i]);
        //auto it = lower_bound(dp.begin(), dp.end(), v[i]);  // 同じ数を含まないようにする場合
        *it = v[i];
        ret = max(ret, static_cast<ll>(it - dp.begin()));
    }
    // LLINF でない最大のインデックス + 1 が LIS になる
    return ret + 1;
}
ll lds(const vector<ll>& v) {
    vector<ll> minus_v;
    for(auto& val : v) { minus_v.push_back(-val); }
    return lis(minus_v);
}

ll N;
vector<ll> A;

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
    }

    auto tmp = lds(A);

    printf("%zu\n", tmp);

    return 0;
}
