#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); \
                cin.tie(0); \
                cout.tie(0)
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(_v)             _v.begin(), _v.end()
#define sz(_v)              (int) _v.size()
#define first(_obj)         (*_obj.begin())
#define last(_obj)          (*prev(_obj.end()))
#define FIND(_obj, _val)    (_obj.find(_val) != _obj.end())
#define RESET(_a, _v)       fill_n(_a,sizeof(_a)/sizeof(_a[0]),_v)
#define REP(_i, _n)         for (int _i = 0; _i < (int) _n; _i++)
#define FOR(_i, _a, _b)     for (int _i = (int) _a; _i <= (int) _b; _i++)
#define FORD(_i, _a, _b)    for (int _i = (int) _a; _i >= (int) _b; _i--)
#define FORIT(_it, _obj)    for (auto _it = _obj.begin(); _it != _obj.end(); _it++)

// DEBUG UTIL
template<typename TF>
void debug(ostream &out, TF const &f) {
    out << f << std::endl;
}
 
template<typename TF, typename ... TR>
void debug(ostream &out, TF const &f, TR const& ... rest) {
    out << f << " ";
    debug( out, rest... );
}
 
#define DEBUG(...) debug(cerr, "[", #__VA_ARGS__, "]:", __VA_ARGS__)

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vi = vector<int>;
using vii = vector<pii>;
using vll = vector<ll>;
using vs = vector<string>;

const int DR[] = {-1, 0, 1, 0, -1, 1, 1, -1}; // ccw
const int DC[] = {0, -1, 0, 1, -1, -1, 1, 1};
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = 1073741823;
const ll INFLL = 4e18;
const int MAX = 3e3;

int N, arr[MAX+5];
ll dp[MAX+5][MAX+5][2];

void read() {
    cin >> N;
    REP(i, N) cin >> arr[i];
}

ll solve(int i, int j, bool p) {
    if (j < i) return 0;

    ll &ret = dp[i][j][p];
    if (ret != -1) return ret;

    if (!p) { // maximize X - Y, play as X
        ret = max(arr[i] + solve(i + 1, j, p ^ 1), arr[j] + solve(i, j - 1, p ^ 1));
    } 
    else { // minimize X - Y, play as Y
        ret = min(-arr[i] + solve(i + 1, j, p ^ 1), -arr[j] + solve(i, j - 1, p ^ 1));
    }

    return ret;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cout << solve(0, N - 1, 0) << "\n";
}

int main() {
    FAST_IO;
    int TC = 1;
    FOR(tc, 1, TC) {
        read();
        solve();
    }
}