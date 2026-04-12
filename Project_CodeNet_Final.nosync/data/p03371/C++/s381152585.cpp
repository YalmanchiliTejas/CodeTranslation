#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define Abs(x)((x) < 0 ? (x) * -1 : (x))
#define rep(x, y) for ((x) = 0; (x) < (y); (x)++)
#define repin(x, y) for ((x) = 0; (x) <= (y); (x)++)
#define nep(x, y) for ((x) = (y) - 1; 0 <= (x); (x)--)
#define nepi(x, y, z) for ((x) = (y) - 1; (z) <= (x); (x)--)
#define repi(x, y, z) for ((x) = (z); (x) < (y); (x)++)
#define repiin(x, y, z) for ((x) = (z); (x) <= (y); (x)++)
#define reps(x, y, z) for ((x) = 0; (x) < (y); (x) += (z))
#define repit(x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define All(x) (x).begin(),(x).end()
#define Mem0(x) memset(x, 0, sizeof(x))
#define Mem1(x) memset(x, -1, sizeof(x))
#define End '\n'
#define Out(x) cout<<(x)<<End
template<typename T> inline bool Max(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template<typename T> inline bool Min(T &x, const T &y) { return x > y ? x = y, 1 : 0; }
template<typename T> using V = vector<T>;
template<typename T> using VV = V<V<T> >;

#define pb push_back
#define mp make_pair

static const ll MOD = 1e9 + 7;
static const double PI = 3.141592653589793;

#define LOCAL 0

int main()
{
#if LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("debug.txt", "w", stderr);
#endif

    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, c, x, y;

    cin >> a >> b >> c >> x >> y;

    int ans0 = 0;
    int ans1 = a * x + b * y;
    int ans2 = max(x, y) * c * 2;
    int d, e;

    d = e = 0;
    d = min(x, y) * 2;
    e = max(x, y) - min(x, y);

    if (max(x, y) == x) ans0 = a * e + c * d;
    else ans0 = b * e + c * d;

    Out(min(ans0, min(ans1, ans2)));

    return 0;
}
