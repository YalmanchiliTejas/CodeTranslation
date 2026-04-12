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
T dup(T x, T y)
{
    return (x + y - 1) / y;
};
template <typename A, size_t N, typename T>
inline void arrayFill(A (&array)[N], const T &val) { std::fill((T *)array, (T *)(array + N), val); }

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

void Main()
{
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    ll sum = 0;

    while (x != 0 || y != 0)
    {
        if (min(x, y) >= 1)
        {
            if (a + b > c * 2)
            {
                sum += c * 2;
            }
            else
            {
                sum += a + b;
            }
            --x;
            --y;
        }
        else
        {
            if (x != 0)
            {
                if (a > c * 2)
                {
                    sum += c * 2;
                }
                else
                {
                    sum += a;
                }
                --x;
            }
            else
            {
                if (b > c * 2)
                {
                    sum += c * 2;
                }
                else
                {
                    sum += b;
                }
                --y;
            }
        }
    }
    cout << sum << endl;
}

int main()
{
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
