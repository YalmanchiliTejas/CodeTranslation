#include <bits/stdc++.h>

#define NREP() for(ll i = 0; i < n; i++)
#define MREP() for(ll j = 0; j < m; j++)
#define REP(i, x, y) for(ll i = x; i < y; i++)
#define ALL(x) (x).begin(), (x).end()
#define MSG(x) cout << x << endl;
#define MSGF(x, n) MSG(fixed << setprecision(n) << x)
#define END(x) cout << x << endl; exit(0);
#define IPT(v, n) REP(i, 0, n){ cin >> v[i]; }
#define YN(x) x ? cout << "YES" << endl : cout << "NO" << endl;
#define Yn(x) x ? cout << "Yes" << endl : cout << "No" << endl;
#define yn(x) x ? cout << "yes" << endl : cout << "no" << endl;

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<ull> vul;
typedef vector<vector<ull>> vvul;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;

const static ll MOD = 1e9 + 7;
const static ll INF = 1LL << 30;

ll a, b, c, d, k, l, m, n, h, w, q, x, y;
string s, t;

ll ans = 0;
ll sum = 0;
ll cnt = 0;
ll cur = 0;
ll tmp = 0;
ll mini = INF;
ll maxi = 0;

double ave = 0.0;

ll mod_pow(ll base, ll power) {
    if (power == 0) return 1;
    if (power == 1) return base % MOD;
    if (power % 2 == 0) return ((mod_pow(base % MOD, (power / 2)) % MOD) * (mod_pow(base, (power / 2)) % MOD)) % MOD;
    return (base % MOD * (mod_pow(base % MOD, power - 1) % MOD)) % MOD;
}

ll mod_fact(ll number) {
    ll ret = 1;
    ll count = 1;
    while (count <= number) {
        ret *= (count % MOD);
        ret %= MOD;
        count++;
    }
    return ret % MOD;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    cin >> n >> s >> k;
    char target = s.at(k-1);
    REP(i, 0, s.size()) {
        if (s.at(i) != target) cout << "*";
        else cout << s.at(i);
    }
    cout << endl;
}
