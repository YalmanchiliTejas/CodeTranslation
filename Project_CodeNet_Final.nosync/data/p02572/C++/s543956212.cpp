#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast")
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
inline int read() {
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-')w = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
#define f(i, l, r) for (int i = l; i <= r; ++i)
#define rf(i, r, l) for (int i = r; i >= l; --i)
#define all(x) (x).begin(), (x).end()
#define l l
#define r r
#define lch (o << 1)
#define rch (o << 1 | 1)
#define mid ((l + r) >> 1)
#define mem(x, y) memset(x, y, sizeof(x))
#define mod1(x) ((x >= mod) && (x -= mod))
#define mod2(x) ((x < 0) && (x += mod))

const int inf = 2e9 + 7;
//const ll INF = INT64_MAX;
double eps = 1e-6;
const int mod = 1e9+7;
const int N = 2e5 + 10;
const double pi = acos(-1.0);
ll power(ll a, ll b) { ll res = 1; while (b) { if (b & 1)res = res * a % mod; a = a * a % mod; b >>= 1; }return res; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
void add(ll& a, ll b) { a += b; mod1(a); mod2(a); }
/*int len, C[N], clen;
int id(int v) { return lower_bound(C + 1, C + len, v) - C; }
void initC() { sort(C + 1, C + clen); len = unique(C + 1, C + 1 + clen) - C - 1; }*/

ll a[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#ifdef local
    freopen("in.txt", "r", stdin);
    int start = clock();
#endif
    int n; cin >> n;
    f(i, 1, n)cin >> a[i];
    ll ans = 0;
    ll sum = a[n];
    rf(i, n - 1, 1) {
        ans += sum * a[i]; ans %= mod; sum += a[i]; sum %= mod;
    }
    cout << ans;

#ifdef local
    int end = clock();
    //cout << '\n' << end - start << "ms";
#endif* /
}