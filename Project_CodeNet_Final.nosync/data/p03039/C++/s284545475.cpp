#include <bits/stdc++.h>
using namespace std;
//#include <boost/multiprecision/cpp_int.hpp>
//using multiInt = boost::multiprecision::cpp_int;

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename Q_temp>
using smaller_queue = priority_queue <Q_temp, vector<Q_temp>, greater<Q_temp> >;

const int INF = (int) 1e9;
const ll LINF = (ll) 4e18;
const ll MOD = (ll) (1e9 + 7);
const double PI = acos(-1.0);

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x_) cerr << #x_ << ":" << x_ << endl;
#define dbg2(x_) for(auto a_ : x_) cerr << a_ << " "; cerr << endl;
#define dbg3(x_ , sx_) rep(i, sx_) cerr << x_[i] << " "; cerr << endl;
vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};

inline ll CEIL(ll a, ll b) {
    return (a + b - 1) / b;
}

//------------------------------------------------------

const ll MAX_N = 200010;
ll fact[MAX_N];
ll fact_inv[MAX_N];

ll pow_mod(ll x, ll y, ll m = MOD) { //x^y mod m
    if (x == 0) return 0;
    ll prod = 1;
    while (y > 0) {
        if (y % 2 == 1) prod = (prod * x) % m;
        x = (x * x) % m;
        y /= 2;
    }
    return prod % m;
}

inline ll inv(ll a) {
    return pow_mod(a, MOD - 2);
}

void init_fact() {
    fact[0] = fact_inv[0] = 1;

    REP(i, 1, MAX_N) {
        fact[i] = (fact[i - 1] * i) % MOD;
        fact_inv[i] = inv(fact[i]);
    }
}

ll C_mod(ll n, ll r) {
    if (n < r) return 0;
    else return ((fact[n] * fact_inv[n - r]) % MOD * fact_inv[r]) % MOD;
}

inline ll H_mod(ll n, ll r) {
    return C_mod(n + r - 1, r);
}

inline ll P_mod(ll n, ll r) {
    return C_mod(n, r) * fact[r];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, k;
    cin >> n >> m >> k;
    init_fact();

    ll E_x = 0, E_y = 0;
    for (ll i = 1; i < n; ++i) {
        E_x += m * m % MOD * (n - i) % MOD * i;
        E_x %= MOD;
    }
    E_x *= inv(C_mod(n * m, 2));
    E_x %= MOD;
    for (ll i = 1; i < m; ++i) {
        E_y += n * n % MOD * (m - i) % MOD * i;
        E_y %= MOD;
    }
    E_y *= inv(C_mod(n * m, 2));
    E_y %= MOD;

    ll E = (E_x + E_y) % MOD; //2つ駒を置いたときのコストの期待値
    E *= C_mod(k, 2);
    E %= MOD;
    ll ans = E * C_mod(n * m, k) % MOD;
    cout << ans << endl;
    return 0;
}
