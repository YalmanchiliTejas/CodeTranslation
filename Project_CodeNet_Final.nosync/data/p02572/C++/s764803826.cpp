#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define clr(a) memset(a, 0, sizeof(a))
#define deb(x) cout << #x << "=" << x << endl
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", &s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define sz(x) x.size()
#define rep(n) for (int i = 0; i < n; i++)
#define repc(i, n) for (int i = 0; i < n; i++)
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define DEC(i, x, y) for (int i = x; i >= y; i--)
#define all(v) v.begin(), v.end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define alla(a, n) a, a + n
using namespace std;

// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ll> vlli;
typedef vector<ii> vii;

template <typename T>
T modpow(T base, T exp, T modulus)
{
    base %= modulus;
    T result = 1;
    while (exp > 0)
    {
        if (exp & 1)
        result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

ll lcm(ll a, ll b) { return (a * (b / __gcd(a, b))); }

// Some contants
const ll inf = 1e12 + 7;
const double eps = 1e-9;
const long double pi = 1.00 * acos(-1.00);

int n;
vlli inp, pre;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /*
    #ifndef ONLINE_JUDGE
        freopen("./input.txt", "r", stdin);
        freopen("./output.txt", "w", stdout);
    #endif

    */
    const ll MOD = 1e9 + 7;
    cin >> n;
    repc(i, n){
        ll tmp;
        cin >> tmp;
        inp.pb(tmp);
    }
    ll curr = 0;
    repc(i, n)
    {
        curr += inp[i];
        pre.pb(curr);
    }

    ll ans = 0;

    FOR(i, 0, n-1){
        ll tmp = (curr - pre[i]) % MOD;
        ans = (ans % MOD + ((inp[i] % MOD) * (tmp)) % MOD) % MOD;
        ans = ans % MOD;
    }

    cout << ans % MOD << endl;

    return 0;
}
