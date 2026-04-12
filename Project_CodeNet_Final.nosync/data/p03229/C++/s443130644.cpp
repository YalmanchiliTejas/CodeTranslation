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
#define nepit(x) for (__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)
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
#define X first
#define Y second

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

    long n;

    cin >> n;

    ll a[n];
    list<ll> ans0;
    list<ll> ans1;
    long index;

    long i, j;

    rep(i, n) cin >> a[i];

    sort(a, a + n);

    ans0.push_front(a[0]);

    i = 1;
    j = n - 1;
    repi(index, n, 1) {
        if (index % 2 == 1) {
            if (i <= j) ans0.push_back(a[j]);
            j--;
            if (i <= j) ans0.push_front(a[j]);
            j--;
        } else {
            if (i <= j) ans0.push_back(a[i]);
            i++;
            if (i <= j) ans0.push_front(a[i]);
            i++;
        }

        if (j < i) break;
    }

    ans1.push_front(a[n - 1]);

    i = 0;
    j = n - 2;
    repi(index, n, 1) {
        if (index % 2 == 1) {
            if (i <= j) ans1.push_back(a[i]);
            i++;
            if (i <= j) ans1.push_front(a[i]);
            i++;
        } else {
            if (i <= j) ans1.push_back(a[j]);
            j--;
            if (i <= j) ans1.push_front(a[j]);
            j--;
        }

        if (j < i) break;
    }

    V<ll> v = V<ll>(All(ans0));
    V<ll> vv = V<ll>(All(ans1));
    ll sum0 = 0;
    ll sum1 = 0;

    repi(i, n, 1) {
        sum0 += Abs(v[i] - v[i - 1]);
        sum1 += Abs(vv[i] - vv[i - 1]);
    }

    Out(max(sum0, sum1));

    return 0;
}
