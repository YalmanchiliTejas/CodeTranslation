#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
//#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define mp(a,b) make_pair(a,b)
#define modsum(a, b) ((a) + (b) >= M ? (a) + (b) - M : (a) + (b))
#define modsubtract(a, b) ((a) - (b) < 0 ? (a) - (b) + M : (a) - (b))
#define modmultiply(a, b) (((a) * (b)) % M)
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define cint const int &
#define SZ(a) ((int)((a).size()))
#define watch(x) cout << (#x) << " = " << (x) << endl;

const double PI = 2 * acos(0.0);

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


inline void transpose(vector<string> &a) {

    int n = a.size();
    if (n == 0) return;
    int m = a[0].size();
    vector<string> b(m, string(n, ' '));
    fori (i, n) fori (j, m) b[j][i] = a[i][j];
    a = b;
}


template<class T>
inline ostream & operator << (ostream &out, vector<T> &a) {
    out << "{";
    fori (i, SZ(a))
        out << a[i] << vector<string>{", ", "}"}[i + 1 == SZ(a)];
    return out;
}

void smain();

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


#ifdef MAX_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#define cerr cout
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\n\n\n";
    cout << "TOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
}


const int N = 3009;

ll dp[N][N];
char did[N][N];
ll a[N];


ll get_dp(int l, int r) {
    if (l > r) return 0;
    if (did[l][r]) return dp[l][r];
    did[l][r] = 1;
    ll & ret = dp[l][r];
    return ret = max(a[l] - get_dp(l + 1, r), a[r] - get_dp(l, r - 1));
}

void smain() {

    int n;
    cin >> n;
    fori (i, n) cin >> a[i];

    cout << get_dp(0, n - 1);
}