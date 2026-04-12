#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#define endl "\n"
#endif
using namespace std;
typedef unsigned long long int lu;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> v;
typedef vector<v> vv;
typedef vector<ld> vld;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
const ll MOD = 1e9 + 7;
const v dx = {1, -1, 0, 0};
const v dy = {0, 0, 1, -1};
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define yesno(f) \
    if (f)       \
        yes else no;
#define noo \
    { no return; }
#define amax(x, y) \
    if (y > x)     \
        x = y;
#define amin(x, y) \
    if (y < x)     \
        x = y;
#define sz(x) (ll) x.size()
#define sq(x) ((x) * (x))

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

template<typename T = ll>
vector<T> ga(ll n, bool oneIndexed = false) {
    vector<T> a = vector<T>(n + oneIndexed);

    for (ll i = 0; i < n; i++) {
        T p;
        cin >> p;
        a[i + oneIndexed] = p;
    }

    return move(a);
}

template<typename T, typename A>
void pa(vector<T, A> const &a, ll begin = 0, ll end = -1) {
    if (end == -1)
        end = sz(a) - 1;
    for (ll i = begin; i <= end; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template<typename T>
T pomod(T x, T y, T mod) {
    T res = 1;
    x = x % mod;

    while (y > 0) {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

ll inv(ll x) {
    return pomod(x, MOD - 2, MOD);
}

void solve() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    v fact, invfact;
    fact = v(n + 1);
    invfact = v(n + 1);
    fact[0] = invfact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
        invfact[i] = inv(fact[i]);
    }

    vv ncr(n + 1, v(n + 1, 0));
    for (ll x = 1; x <= n; x++) {
        ncr[x][0] = 1;
        for (ll y = 1; y <= x; y++) {
            ncr[x][y] = ((ncr[x][y - 1] * (x - y + 1)) % MOD) * inv(y);
            ncr[x][y] %= MOD;
        }
    }

    vector<vv> combi(n + 1, vv(n + 1));
    for (ll sum = 1; sum <= n; sum++) {
        for (ll groupSize = 1; groupSize <= n; groupSize++) {
            ll curr = 1, left = sum;

            for (ll use = 1; use <= n; use++) {
                if (groupSize * use > sum)break;
                curr *= ncr[left][groupSize];
                curr %= MOD;
                left -= groupSize;

                ll ans = curr * invfact[use];
                ans %= MOD;
                combi[sum][groupSize].push_back(ans);
            }
        }
    }

    vv dp(n + 2, v(n + 2, 0));
    dp[0][b] = 1;
    for (ll i = c; i <= d; i++) {
        if (i * b > n)break;
        dp[i * b][b] = combi[i * b][b][i - 1];
    }

    for (ll groupSize = b - 1; groupSize >= a; groupSize--) {
        for (ll usage = c; usage <= d; usage++) {
            ll sum = groupSize * usage;

            for (ll s = sum; s <= n; s++) {
                // TODO: multiply here by the number of ways to choose the people as well
                // can be modeled using another 3 state dp of size n^2 logn
                // dp[s][gs][c] = number of ways to choose c groups from s people of groupsize gs
                ll add = combi[s][groupSize][usage - 1] * dp[s - sum][groupSize + 1];
                add %= MOD;
                dp[s][groupSize] += add;
                dp[s][groupSize] %= MOD;
            }
        }
        for (ll s = 0; s <= n; s++) {
            dp[s][groupSize] += dp[s][groupSize + 1];
            dp[s][groupSize] %= MOD;
        }
    }


    ll ans = dp[n][a];

    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // ll t;cin >> t;while(t--)
    solve();
    return 0;
}