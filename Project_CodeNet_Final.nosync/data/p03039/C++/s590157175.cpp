#include <bits/stdc++.h>
#define FI first
#define SE second
#define EPS 1e-9
#define ALL(a) a.begin(),a.end()
#define SZ(a) int((a).size())
#define MS(s, n) memset(s, n, sizeof(s))
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)
#define FORALL(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define WHATIS(x) cout << #x << " is " << x << endl;
#define ERROR(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
//__builtin_ffs(x) return 1 + index of least significant 1-bit of x
//__builtin_clz(x) return number of leading zeros of x
//__builtin_ctz(x) return number of trailing zeros of x

using namespace std;
using ll = long long;
using ld = double;
typedef pair<int, int> II;
typedef pair<ll, II> III;
typedef complex<ld> cd;
typedef vector<cd> vcd;

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << endl;
    err(++it, args...);
}

const ll MODBASE = 1000000007LL;
const int MAXN = 400010;
const int MAXM = 100010;
const int MAXK = 510;

int n, m, k;
ll gt[MAXN], rev[MAXN];

ll getK(ll k) {
    return k * (k - 1) / 2 % MODBASE;
}

ll mu(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a % MODBASE;
    ll g = mu(a, b/2);
    if (b % 2) return g * g % MODBASE * a % MODBASE;
    return g * g % MODBASE;
}

ll C(ll n, ll k) {
    if (k > n) return 0;
    if (n < 0) return 0;
    return gt[n] * rev[n-k] % MODBASE * rev[k] % MODBASE;
}

ll tinh(ll g) {
    return g * (g + 1) / 2 % MODBASE;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    ll calc = getK(k);
    
    gt[0] = 1;
    rev[0] = mu(gt[0], MODBASE-2);
    FOR(i,1,400000) {
        gt[i] = gt[i-1] * i % MODBASE;
        rev[i] = mu(gt[i], MODBASE-2);
    }

    ll other = C(n * m - 2, k - 2);

    ll res = 0;
    FOR(i,1,n) {
        ll h = tinh(n-i);
        ll z = h * m % MODBASE;
        res = (res + z * other % MODBASE * m % MODBASE) % MODBASE;
    }
    FOR(i,1,m) {
        ll h = tinh(m-i);
        ll z = h * n % MODBASE;
        res = (res + z * other % MODBASE * n % MODBASE) % MODBASE;
    }

    cout << res;
    return 0;
}