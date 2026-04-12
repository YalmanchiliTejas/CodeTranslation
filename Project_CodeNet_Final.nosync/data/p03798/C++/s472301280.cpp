#include <bits/stdc++.h>

using namespace std;

#define DUMP(x) std::cerr << (#x) << " = " << (x) << "\n"
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, k, n) for (int i = (k); i < (int)(n); ++i)
#define ALL(r) r.begin(), r.end()
#define YES puts("YES")
#define Yes puts("Yes")
#define NO puts("NO")
#define No puts("No")
#define IMP puts("IMPOSSIBLE")
#define Imp puts("Impossible")
#define imp puts("impossible")
#define M1 puts("-1")
#define pb push_back

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    os << "{";
    rep(i, v.size()) os << v[i] << (i == (int)v.size() - 1 ? "" : ", ");
    os << "}";
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
using pll = pair<ll, ll>;
using setint = set<int32_t>;
using setstr = set<string>;
using qint = queue<int32_t>;
using qpint = queue<pint>;

constexpr std::int32_t INF = 1001001001;
constexpr std::int64_t LINF = 1001001001001001001;

char rev(char c)
{
    if (c == 'S')
        return 'W';
    else
        return 'S';
}

bool is_ok(char ox, char mid, char left, char right)
{
    if ((ox == 'o' && mid == 'S') || (ox == 'x' && mid == 'W'))
    {
        return left == right;
    }
    else
    {
        return !(left == right);
    }
}

void Main()
{
    int n = in();
    string s = in();
    vstr v(4);

    rep(i, 4)
    {
        rep(j, n)
        {
            if (j == 0)
            {
                if (i == 0 || i == 1)
                    v[i].pb('S');
                else
                    v[i].pb('W');
            }
            else if (j == 1)
            {
                if (i == 0 || i == 2)
                    v[i].pb('S');
                else
                    v[i].pb('W');
            }
            else
            {
                if (s[j - 1] == 'o')
                {
                    if (v[i][j - 1] == 'S')
                        v[i].pb(v[i][j - 2]);
                    else
                        v[i].pb(rev(v[i][j - 2]));
                }
                else
                {
                    if (v[i][j - 1] == 'S')
                        v[i].pb(rev(v[i][j - 2]));
                    else
                        v[i].pb(v[i][j - 2]);
                }
            }

            if (j == n - 1)
            {
                if (is_ok(s[j], v[i][j], v[i][j - 1], v[i][0]) && is_ok(s[0], v[i][0], v[i][j], v[i][1]))
                {
                    cout << v[i] << endl;
                    return;
                }
            }
        }
    }
    M1;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
