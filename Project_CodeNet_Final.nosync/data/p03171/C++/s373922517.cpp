#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define SPEED ios_base::sync_with_stdio(false); cin.tie(NULL);
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define RFOR(i, b, a) for (ll i = b; i >= a; --i)
#define ALL(x) x.begin(), x.end()
#define DEBUG(args...) { string _s = #args; replace(ALL(_s), ' ', '\0');\
replace(ALL(_s), ',', ' ');\
stringstream _ss(_s); istream_iterator<string> _it(_ss); _debug(_it, args);}
#define endl "\n"
#define F first
#define S second
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void _debug(istream_iterator<string>) {}
template<typename T, typename... Args>
void _debug(istream_iterator<string> it, T first, Args... args) {
    cerr << ">> " << *it << " : " << first << endl; _debug(++it, args...);
}
template <typename T1, typename T2>
inline ostream& operator << (ostream& out, const pair<T1, T2>& p) {
    return out << "(" << p.F << ", " << p.S << ")";
}
template<typename T>
inline ostream& operator << (ostream& out, const vector<T>& v) {
    if (v.empty()) return out << "[]";
    else { out << '['; for (auto& e : v) { out << e << ", "; } return out << "\b\b]"; }
}
template<typename T>
inline ostream& operator << (ostream& out, const set<T>& s) {
    if (s.empty()) return out << "{}";
    else { out << '{'; for (auto& e : s) { out << e << ", "; } return out << "\b\b}"; }
}
template<typename T>
inline ostream& operator << (ostream& out, const unordered_set<T>& s) {
    return out << set<T>(ALL(s));
}
template<typename T1, typename T2>
inline ostream& operator << (ostream& out, const map<T1, T2>& m) {
    if (m.empty()) return out << "{}";
    out << '{'; for (auto& p : m) { out << p << ", "; } return out << "\b\b}";
}
template<typename T1, typename T2>
inline ostream& operator << (ostream& out, const unordered_map<T1, T2>& m) {
    return out << map<T1, T2>(ALL(m));
}
template<typename T>
inline ostream& operator << (ostream& out, const ordered_set<T>& s) {
    return out << set<T>(ALL(s));
}

typedef long long ll;
typedef long double ld;
typedef vector<long long> vll;
typedef pair<ll, ll> pll;
typedef vector<pair<ll, ll>> vpll;
typedef unordered_map<ll, ll> STll;
/************************************** MAIN PROGRAM ********************************************/
const int MAX = 3001;

ll dp[MAX][MAX][2];
int main()
{
   //freopen("input.txt", "r", stdin);
    SPEED
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &e : a) {
        cin >> e;
    }

    for (int sz = 1; sz <= n; ++sz) {
        for (int i = 0; i + sz - 1 < n; ++i) {
            int j = i + sz - 1;

            for (int player : {0, 1}) {
                if (i == j) {
                    dp[i][j][player] = (player) ? -a[i] : a[i];
                } else if (player == 0) {
                    dp[i][j][player] = max(a[i] + dp[i + 1][j][!player], a[j] + dp[i][j - 1][!player]);
                } else {
                    dp[i][j][player] = min(-a[i] + dp[i + 1][j][!player], -a[j] + dp[i][j - 1][!player]);
                }
               // cout << i << ' ' << j << ' ' << player << ' ' << dp[i][j][player] << endl;
            }
        }
    }
    cout << dp[0][n - 1][0];
}
/************************************** END OF PROGRAM ******************************************/
