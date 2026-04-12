#include <bits/stdc++.h>
#include <regex>
#ifdef _DEBUG
#include "debug.h"
#endif
#define int ll
#define FOR(i, s, e) for (int i = int(s); i < int(e); ++i)
#define REP(i, e) FOR(i, 0, e)
#define mkpr make_pair
#define mktp make_tuple
#define tv(tp, i) get<(i)>(tp)
#define CLEAR(obj) obj = decltype(obj)()
#define var auto
#define OUT(type) type &
#define IN(type) const type &
#define self (*this)
#define in :
#define True true
#define False false
using namespace std; using str = string; using cstr = const str;
using ll = long long; using ull = unsigned long long; using cint = const int; using cll = const ll;
using vi = vector<int>; using vvi = vector<vi>; using vl = vector<ll>; using vvl = vector<vl>;
using vb = vector<bool>; using vvb = vector<vb>; using vd = vector<double>; using vvd = vector<vd>;
using vc = vector<char>; using vvc = vector<vc>; using vs = vector<string>;
using pii = pair<int, int>; using pll = pair<ll, ll>; using pdd = pair<double, double>; using psl = pair<string, ll>;
using tiii = tuple<int, int, int>; using tlll = tuple<ll, ll, ll>;
static const int MGN = 10; static const int ARYSZ_MAX = (int)1e7;
static const ll LINF = LLONG_MAX/2;
#ifdef int
static const int INF = LINF;
#else
static const int INF = INT_MAX/2;
#endif
static double EPS = 1e-9;
static inline bool DBLEQ(double a, double b) {return abs(a - b) < EPS;}
static inline void EPR(str msg) {cerr << msg << endl;}
static inline void AST(bool exp, str msg) {if(!exp){EPR(msg);} assert(exp);}
static inline void TAST(bool exp, str msg) {if(!exp){EPR(msg);} while(!exp){}}

int N, M;
vvi es;
vb vis;
int cnt;
int ans;
void dfs(int x, int px = - 1) {
    if (vis[x])
        return;
    vis[x] = True;
    cnt += 1;

    if (cnt == N) ans += 1;

    for (var nx in es[x]) {
        if (nx == px) continue;
        dfs(nx, x);
    }

    vis[x] = False;
    cnt -= 1;
}


int32_t main(int32_t argc, char* argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);
#ifdef IMPORT_SAMPLE
    vs args(argv, argv+argc);
    string sample = make_sample(args, "sample-1");
    ifstream ifs(sample); cin.rdbuf(ifs.rdbuf());
#endif


    cin >> N>>M;
    vi A(M), B(M);
    REP(i,M) {
        cin >> A[i] >> B[i];
        A[i] -= 1; B[i] -= 1;
    }

    es = vvi(N);
    REP(i,M) {
        es[A[i]].push_back(B[i]);
        es[B[i]].push_back(A[i]);
    }
    vis = vb(N, False);
    cnt = 0;
    ans = 0;
    dfs(0);

    cout << ans << endl;


    return 0;
}
