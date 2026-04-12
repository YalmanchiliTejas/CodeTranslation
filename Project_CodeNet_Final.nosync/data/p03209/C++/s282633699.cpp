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
const int limit = 200010;

#define REP(i,m,n) for(ll i = m; i < (ll)(n); ++i)
#define rep(i,n) REP(i, 0, n)
#define MP make_pair
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

//------------------------------------------------------

ll how_many[51]; //バーガーの段数

void init_how_many() {
    how_many[0] = 1;
    for (int i = 1; i <= 50; i++) {
        how_many[i] = 3 + 2 * how_many[i - 1];
    }
}

ll count_func(ll l, ll x) {
    if (x == 1) return (l == 0 ? 1 : 0);
    else if (x == how_many[l]) return 1 + 2 * count_func(l - 1, how_many[l - 1]);
    else if (x == (how_many[l] + 1) / 2) return 1 + count_func(l - 1, how_many[l - 1]);
    else if (1 < x && x < (how_many[l] + 1) / 2) {
        return count_func(l - 1, x - 1);
    } else if ((how_many[l] + 1) / 2 < x && x < how_many[l]) {
        return 1 + count_func(l - 1, how_many[l - 1])
                + count_func(l - 1, x - 2 - how_many[l - 1]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, x;
    cin >> n >> x;
    init_how_many();
    cout << count_func(n, x) << endl;
    return 0;
}