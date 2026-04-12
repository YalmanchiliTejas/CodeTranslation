#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cerr << (#x) << " = " << (x) << "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, k, n) for (int i = (k); i < (int)(n); ++i)
#define ALL(r) r.begin(), r.end()
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define IMP cout << "IMPOSSIBLE" << endl
#define Imp cout << "Impossible" << endl
#define imp cout << "impossible" << endl
#define M1 cout << "-1" << endl
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    os << "{";
    rep(i, v.size()) os << v[i] << (i == (int)v.size() - 1 ? "" : ", ");
    os << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &p)
{
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
template <typename T>
T dup(T x, T y)
{
    return (x + y - 1) / y;
};
template <typename A, size_t N, typename T>
inline void arrayFill(A (&array)[N], const T &val) { std::fill((T *)array, (T *)(array + N), val); }
struct in
{
    const size_t n = 0;
    in() = default;
    in(size_t n) : n(n){};
    template <typename T>
    operator T()
    {
        T ret;
        cin >> ret;
        return ret;
    }
    template <typename T>
    operator vector<T>()
    {
        assert(n != 0);
        vector<T> ret(n);
        for (auto &x : ret)
            cin >> x;
        return ret;
    }
};

using ll = int64_t;
using vint = vector<int32_t>;
using vvint = vector<vint>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vstr = vector<string>;
using pint = pair<int32_t, int32_t>;
using vpint = vector<pint>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using setint = set<int32_t>;
using setstr = set<string>;
using qint = queue<int32_t>;
using qpint = queue<pint>;

constexpr std::int32_t INF = 1001001001;
constexpr std::int64_t LINF = 1001001001001001001;

ll dp[110][3][7];

void Main()
{
    arrayFill(dp, 0);
    string s = in();
    int K = in();
    int l = s.size();

    dp[0][0][0] = 1;
    rep(i, l)
    {
        const int D = s[i] - '0';
        rep(j, 2)
        {
            rep(k, 4)
            {
                for (int d = 0; d <= (j ? 9 : D); ++d)
                {
                    // 0 を入れる場合
                    if (d == 0)
                    {
                        dp[i + 1][j || (d < D)][k] += dp[i][j][k];
                    }
                    else
                    {
                        if (k == K)
                            continue;
                        // 0 以外を入れる場合
                        dp[i + 1][j || (d < D)][k + 1] += dp[i][j][k];
                    }
                }
            }
        }
    }

    cout << dp[l][0][K] + dp[l][1][K] << endl;
}

signed main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
