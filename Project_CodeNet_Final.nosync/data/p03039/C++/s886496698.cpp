#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

ll n, m, k;

ll mod_pow(ll x, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return res;
}

ll mod_inverse(ll x) {
    return mod_pow(x, mod-2);
}

const int max_n = 1000000;
ll fact[max_n];
ll fact_inv[max_n];
void calc_fact() {
    fact[0] = 1;
    for (ll i = 1; i < max_n; i++)
        fact[i] = (fact[i-1] * i) % mod;
    fact_inv[max_n-1] = mod_inverse(fact[max_n-1]);
    for (ll i = max_n-2; i >= 0; i--)
        fact_inv[i] = (fact_inv[i+1] * (i+1)) % mod;
}
ll mod_comb(ll n, ll k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return (fact[n] * fact_inv[k] % mod) * fact_inv[n-k] % mod;
}

ll solve() {
    ll b = 0;
    for (int i = 1; i < m; i++) {
        b += n * n * i * (m-i);
        b %= mod;
    }
    for (int i = 1; i < n; i++) {
        b += m * m * i * (n-i);
        b %= mod;
    }

    calc_fact();
    return b * mod_comb(n*m-2, k-2) % mod;
}

void input() {
    cin >> n >> m >> k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
