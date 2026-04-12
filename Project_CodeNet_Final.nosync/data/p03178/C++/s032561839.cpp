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
#else
#define cerr if (0) cerr
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\n\n\n";
    cout << "TOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
}

const int N = 10009;
const int D = 109;
const int T = 10;
const ll M = 1e9 + 7;

int dp[N][D][T + 1];

vi a;

int d;

ll dfs(int ind, int rem) {
    if (ind == -1) return 0;
    ll ret = 0;
    for (int dig = 0; dig < a[ind]; ++dig) {
        ret += dp[ind][rem][dig];
    }
    rem = (rem - a[ind] % d + d) % d;
    return ret + dfs(ind - 1, rem);
}

void smain() {

    string s;
    cin >> s;
    a.resize(s.size());
    fori (i, a.size()) a[i] = s[i] - '0';
    reverse(ALL(a));
    int r = 1;
    for (int i = 0; r; ++i) {
        if (i == a.size()) a.push_back(0);
        a[i] += r;
        r = a[i] / 10;
        a[i] %= 10;
    }
    cin >> d;
    int n = a.size();
    fori (dig, T) {
        dp[0][dig % d][dig] = 1;
        dp[0][dig % d][T] = (dp[0][dig % d][T] + 1) % M;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < d; ++j) {
            for (int dig = 0; dig < T; ++dig) {
                dp[i][j][dig] = dp[i - 1][(d + j - dig % d) % d][T];
                dp[i][j][T] = (dp[i][j][T] + dp[i][j][dig]) % M;
            }
        }
    }
    cout << (dfs(n - 1, 0)  + M - 1) % M;
}