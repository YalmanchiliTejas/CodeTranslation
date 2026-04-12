#include <bits/stdc++.h>
using namespace std;

string to_string(string s) { return '"' + s + '"'; }
string to_string(char c) { string s = "'"; s += c; return s + "'"; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } 
template <typename A>
string to_string(A v) {
    bool first = true; 
    string res = "{";
    for (const auto &x : v) {
        if (!first) res += ", ";
        first = false;
        res += to_string(x);
    }
    res += "}"; 
    return res;
}
istream_iterator<string> eos;
void dbg_out(istream_iterator<string> it) { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(istream_iterator<string> it, Head H, Tail... T) {
    cerr << *it << " = " << to_string(H);
    if(++it != eos) cerr << ", ";
    dbg_out(it, T...);
}
#ifdef LOCAL
    #define dbg(...) { string _s = #__VA_ARGS__; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); dbg_out(_it, __VA_ARGS__); }
#else
    #define dbg(...)
#endif

#define int long long
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define MP make_pair
#define sz(v) ((int)(v).size())
#define fr(i, j, k) for(int i = j; i < k; i++)
#define nl "\n"
typedef pair<int, int> pii;
typedef vector <int> vi;

pii dir[8] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {1, 1}, {-1, -1} , {-1, 1}, {1, -1} };

const int inf = (1LL << 60), mod = 998244353, nn = 3003;
int n, s;
int a[nn];
int dp[nn][nn];

int fun(int ind, int sum) {
    if(sum == 0) return n - (ind - 2);    // for this set last element is idx-1, and we can take R from idx-1 to n for this set
    if(ind > n) return 0;
    int &res = dp[ind][sum];
    if(res != -1) return res;

    int can = fun(ind + 1, sum);
    if(sum - a[ind] >= 0) can += fun(ind + 1, sum - a[ind]);
    return res = can % mod;
}

void solve(){
    cin >> n >> s;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++) {
        ans = (ans + fun(i, s)) % mod;         // fix L = i, ignoring all elements previous to i 
    }
    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int tc = 1; tc <= T; tc++){
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}