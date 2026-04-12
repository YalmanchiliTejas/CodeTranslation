# include<bits/stdc++.h>

#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair
#define input freopen("input.txt","r",stdin);
#define output freopen("output.txt","w",stdout);
#define fast_io ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
#define fix cout << fixed << setprecision(15);
//#define left left228
//#define right right228
//#define next next228
#define rank rank228
//#define prev prev228
#define y1 y1228
#define dout if(debug) cout
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int> ;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
using vi = vector<int> ;
using vll = vector<ll> ;
using vpii = vector<pii> ;
const ll infll = 1e18 + 3;
const int maxn = 1e6 + 77;
const int nmax = 1e6 + 577;
const ll basell = 1e18 + 3;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
const int inf = 1009000999;
const int nv = 100505;
const int baseint = 1000200013;
const ld PI = acos(-1.0);
inline bool EQ(ld a, ld b) { return fabs(a-b) < 1e-9; }
inline bool IF(int a, int b, int c) { return (a >= b && a <= c); }
inline bool IFS(int a, int b, int c) { return (a > b && a < c); }
template<typename T> inline istream &operator>> (istream &_in, vector<T> &_v) { for (auto &_i : _v) { _in >> _i; } return _in; }
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
//typedef pair<int, int> pt;
//#define x first
//#define y second
//ifstream cin("input.txt");
//ofstream cout("output.txt");
/*
sort(a, a + n, [&](pair<pt, int> a, pair<pt, int> b){if (a.x.x != b.x.x)
        return a.x.x < b.x.x; return a.x.y > b.x.y;});
for(int c : s)
for(int &i : a) cin >> i;
for(int c = 'a'; c <= 'z'; ++c)
vector<vector<ll>> dp(n, vector<ll>(n+2));
__int128;
char 0 = int 48;
char c = cin;
int h = (int)c - 48;
*/

/*char memory[(int)1e8];

char memorypos;

inline void * operator new(size_t n){
    char * ret = memory + memorypos;
    memorypos += n;
    return (void *)ret;
}

inline void operator delete(void *){}
*/

ll a[3000];

ll dp[3000][3000];

ll dfs(int x,int y) {
    if (x > y) {
        return dp[x][y] = 0;
    }
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    return dp[x][y] = max(a[x] - dfs(x + 1, y), a[y] - dfs(x, y - 1));
}

int inline solve() {
    //input;//,output;
    //fix;
    fast_io;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        fill(dp[i], dp[i] + n, -1);
    }
    cout << dfs(0, n - 1);
    return 0;
}

int32_t main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}
/*
6
2 1 6 3 4 5
2 1 3 4 5 6
6 0
1 7 8 2 4 6
 * */