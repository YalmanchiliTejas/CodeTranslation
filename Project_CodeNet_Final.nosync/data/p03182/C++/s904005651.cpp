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
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\n\n\n";
    cout << "TOTAL EXECUTION TIME: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
}

const int N = 2e5 + 9;
const ll oo = 1e18;
ll t[N << 2];
ll pushing[N << 2];
struct SegmentTree {

    SegmentTree() {
        fill(t, t + (N << 2), 0);
        fill(pushing, pushing + (N << 2), 0);
    }

    void push(int v) {
        pushing[v << 1] += pushing[v];
        t[v << 1] += pushing[v];
        pushing[v << 1 | 1] += pushing[v];
        t[v << 1 | 1] += pushing[v];
        pushing[v] = 0;
    }

    void upd(int v, int tl, int tr, int l, int r, ll inc) {
        if (l > r) return;
        if (tl == l && tr == r) {
            t[v] += inc;
            pushing[v] += inc;
            return;
        }
        push(v);
        int tm = tl + tr >> 1;
        upd(v << 1, tl, tm, l, min(tm, r), inc);
        upd(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r, inc);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }

    ll get(int v, int tl, int tr, int l, int r) {
        if (l > r) return -oo;
        if (tl == l && tr == r) {
            return t[v];
        }
        push(v);
        int tm = tl + tr >> 1;

        return max(
                get(v << 1, tl, tm, l, min(tm, r)),
             get(v << 1 | 1, tm + 1, tr, max(tm + 1, l), r)
        );
    }
};

int n, m;

int lf[N], rf[N];
ll a[N];
ll dp[N];

vi st[N], fin[N];

void smain() {
    cin >> n >> m;
    fori (i, m) {
        cin >> lf[i] >> rf[i] >> a[i];
        st[lf[i]].push_back(i);
        fin[rf[i]].push_back(i);
    }
    SegmentTree tree;
    for (int i = 1; i <= n; ++i) {
        for (auto ind : st[i]) {
            tree.upd(1, 0, n, 0, i - 1, a[ind]);
        }
        dp[i] = tree.get(1, 0, n, 0, i - 1);
        tree.upd(1, 0, n, i, i, dp[i]);
        for (auto ind : fin[i]) {
            tree.upd(1, 0, n, 0, lf[ind] - 1, -a[ind]);
        }
//        cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    cout << *max_element(dp, dp + n + 1);
}