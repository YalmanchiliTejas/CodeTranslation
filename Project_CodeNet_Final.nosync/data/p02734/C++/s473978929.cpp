#include "vector"
#include "set"
#include "map"
#include "unordered_set"
#include "unordered_map"
#include "string"
#include "iostream"
#include "algorithm"
#include "queue"

using namespace std;

#define ll long long
#define INF 2e9
#define INF2 4611686018427387904
//#define MOD 1000000007
#define MOD 998244353
#define MAX_SIZE 1000000000

typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) { bool first = true; for (const auto& j: v) { if (!first) { os << " "; } first = false; os <<j; } os << "\n"; return os; }
template<typename T>
istream& operator>>(istream& is, vector<T>& v) { for (auto& elem : v) { is >> elem; } return is; }

vector<ll> f;
void set_f(int n) { f.resize(n+1); f[0] = 1; for (int i=1; i<= n; i++) { f[i] = (f[i-1] * i) % MOD;} }
ll nod(ll a, ll b) { if (b == 0) { return a; } else { return nod(b, a % b); } }
ll pw(ll x, ll n, ll m=MOD) { if (n == 0) { return 1;} if (n%2 == 0) { return pw((x*x) % m, n/2, m); } return (pw(x, n-1, m) * x) % m; }
ll dv(ll a, ll b) { return (a * pw(b, MOD - 2)) % MOD; }
ll c_n_k(int n, int k) { if (k > n) { return 0; } if (k < 0) { return 0; } return dv(dv(f[n], f[k]), f[n-k]); }


void solve() {
    int n, s;
    cin >> n >> s;

    vi a(n);
    cin >> a;

    vll dp1(s+1, 0);
    dp1[0] = 1;

    ll ans = 0;
    for (int i=0; i<n; i++) {
        if (a[i] < s) {
            ans = (ans + dp1[s - a[i]] * (n-i)) % MOD;
        }
        if (a[i] == s) {
            ans = (ans + (i+1) * (n-i)) % MOD;
        }

        vll dp2 = dp1;
        for (int j=a[i]; j<=s; j++) {
            if (j == a[i]) {
                dp2[j] += i+1;
            } else {
                dp2[j] += dp1[j - a[i]];
            }

            dp2[j] %= MOD;
        }

        dp1 = dp2;
    }

    cout << ans;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    if (0) {
        int tests;
        cin >> tests;
        for (int t = 1; t <= tests; t++) {
            //cout << "Case #" << t << ": ";
            solve();
            //cout << "\n";
        }
    } else {
        solve();
        cout << endl;
    }

    return 0;
}