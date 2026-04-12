#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#pragma region Macros
using ll = long long;
#define int ll
using pii = pair<int, int>;
using tiii = tuple<int, int, int>;
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
#define IOS\
    ios::sync_with_stdio(false);\
    cin.tie(0);\
    cout.tie(0);
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SORT(name) sort(name.begin(), name.end())
#define RSORT(name)\
    SORT(name);\
    reverse(all(name));
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
template <class T> inline void print(T x){ cout << x << '\n';}
template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
#pragma endregion

#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const int MOD = 1000000007;
const int MAX_N = 100010;

int RMaxQ(int a, int b) {
    return max(a, b);
}
int MaxE() { return 0; }

signed main() {
    IOS;

    int N, Q;
    cin >> N >> Q;
    V<> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    segtree<int, RMaxQ, MaxE> segmax(A);

    REP(i, Q) {
        int q;
        cin >> q;
        if(q == 1) {
            int x, v;
            cin >> x >> v;
            x--;
            segmax.set(x, v);
        }
        else if(q == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            print(segmax.prod(l, r));
        }
        else {
            int x, v;
            cin >> x >> v;
            x--;

            if(v > segmax.prod(x, N)) {
                print(N + 1);
                continue;
            }

            int lb = x, ub = N - 1;
            while(ub - lb > 1) {
                int mid = (lb + ub) / 2;
                int val = segmax.prod(x, mid + 1);
                if(v <= val) { ub = mid; }
                else { lb = mid; }
            }
            if(v <= segmax.prod(x, lb + 1)) {
                print(lb + 1);
            }
            else {
                print(ub + 1);
            }
        }
    }

    return 0;
}
