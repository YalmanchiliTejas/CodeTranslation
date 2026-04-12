#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)
#define rep1(i,n) for (int i = 1; i <= int(n); i++)
#define repR(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = int(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) (x).begin(), (x).end()
#define allR(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
#ifdef LOCAL
#define dump(...) cerr << "[" << __LINE__ << ":" << __FUNCTION__ << "] ", my_dmp(#__VA_ARGS__, __VA_ARGS__)
void my_dmp(const char*) { cerr << endl; }
template <class T, class... U> void my_dmp(const char *s, T const& x, U const& ...y) { const char *o = "({[", *e = "]})"; for (int i = 0; *s != '\0'; cerr << *s++) { if (count(o,o+3,*s)) i++; if (count(e,e+3,*s)) i--; if (!i && *s == ',') break; } cerr << " = " << x; if (*s == ',') cerr << ", ", s++; my_dmp(s, y...); }
#else
#define dump(...)
#endif
using ll = long long;
using ld = long double;
#define int ll
#define double ld
template <class T> using pque_max = priority_queue<T>;
template <class T> using pque_min = priority_queue<T, vector<T>, greater<T> >;
template <class T, class = typename T::iterator, class = typename enable_if<!is_same<T, string>::value>::type>
ostream& operator<<(ostream& os, T const& v) { os << "{"; for (auto const& x : v) os << " " << x; return os << " }"; }
template <class T> istream& operator>>(istream& is, vector<T>& v) { for (auto& x : v) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct my_Init { my_Init() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } my_init;

template <class T, size_t d, class = typename enable_if<(d == 0)>::type> constexpr auto make_v(T const& x = {}) { return x; }
template <class T, size_t d, class... U, class = typename enable_if<(d > 0)>::type> constexpr auto make_v(size_t n, U... x) { auto val = make_v<T,d-1>(x...); return vector<decltype(val)>(n, move(val)); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T> constexpr bool chmin(T& x, T const& y) { if (x > y) { x = y; return true; } return false; }
template <class T> constexpr bool chmax(T& x, T const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b,e,typename iterator_traits<It>::value_type{}); }
const ll INF = (1LL<<62)-1; // ~ 4.6e18
////////////////////////////////
int n;
vector<int> a;
const int NN = 3000 + 10;
int dp[NN][NN][2], used[NN][NN][2];

int rec(int l, int r, int turn) {
    int &res = dp[l][r][turn], &u = used[l][r][turn];
    if (u) return res;
    u = 1;
    if (l == r) return res = (turn ? a[l] : -a[l]);
    if (turn) {
        int x = a[l] + rec(l+1,r,1-turn);
        int y = a[r] + rec(l,r-1,1-turn);
        res = max(x,y);
    } else {
        int x = -a[l] + rec(l+1,r,1-turn);
        int y = -a[r] + rec(l,r-1,1-turn);
        res = min(x,y);
    }
    return res;
}

int32_t main() {
    cin >> n;
    a.resize(n); cin >> a;
    cout << rec(0,n-1,+1) << endl;
    //
    rep (i,NN) rep (j,NN) rep (k,2) if (used[i][j][k]) {
        dump(i,j,k,dp[i][j][k]);
    }
}
