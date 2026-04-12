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
#define repis(x, y, z, s) for ((x) = (z); (x) < (y); (x) += (s))
#define repit(x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define nepit(x) for (__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)

#define All(x) (x).begin(),(x).end()

#define Mem0(x) memset(x, 0, sizeof(x))
#define Mem1(x) memset(x, -1, sizeof(x))

#define Unique(v) v.resize(unique(All(v)) - v.begin())

#define peq(p0, p1)(p0.first == p1.first && p0.second == p1.second)

#define End '\n'
#define Out(x) cout<<(x)<<End
#define OutP(p, sep, end) cout<<p.first<<sep<<p.second<<end

template<typename T> inline bool Max(T &x, const T &y) { return x < y ? x = y, 1 : 0; }
template<typename T> inline bool Min(T &x, const T &y) { return x > y ? x = y, 1 : 0; }
template<typename T> using V = vector<T>;
template<typename T> using VV = V<V<T> >;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define lb std::lower_bound
#define ub std::upper_bound

#define lbi(v, x) lb(All(v), (x))-v.begin()
#define ubi(v, x) ub(All(v), (x))-v.begin()

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
	//std::cout.precision(18);

    int x;

	cin >> x;

	if (x == 3 || x == 5 || x == 7) Out("YES");
	else Out("NO");
	
	return 0;
}
