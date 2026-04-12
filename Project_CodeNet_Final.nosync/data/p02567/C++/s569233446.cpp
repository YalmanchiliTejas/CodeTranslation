#include <bits/stdc++.h>
using namespace std;
#define ACL
#ifdef ACL
#include <atcoder/all>
using namespace atcoder;
#endif
#define int int64_t
#define REP(i, n) for (int i = 0; (i) < (int)(n); ++ (i))
#define REP3(i, m, n) for (int i = (m); (i) < (int)(n); ++ (i))
#define REP_R(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define REP3R(i, m, n) for (int i = (int)(n) - 1; (i) >= (int)(m); -- (i))
#define REPP(i, n) for (int i = 1; (i) < (int)(n+1); ++ (i))
#define REPR(i, n) for (int i = (int)(n) - 1; (i) >= 0; -- (i))
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, m, n) for(int i=(m)-1; i>=(n); i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
using Graph = vector<vector<int> >;
using WeightedGraph = vector<vector<pair<int, int> > >;
using LD = long double;
using VI = vector<int>;
using VVI = vector<vector<int> >;
using PII = pair<int, int>;
template <typename T> using V = vector<T>;
template <typename T> using VV = vector<vector<T> >;
template <typename T> using VVV = vector<vector<vector<T> > >;
void print() {cout << endl;}
template <typename Head, typename... Tail> void print(Head&& head, Tail&&... tail) {cout << head; if (sizeof...(tail) != 0) cout << " ";print(forward<Tail>(tail)...);}
template <typename T> void print(vector<T> &vec) {for (auto& a : vec) {cout << a; if (&a != &vec.back()) cout << " ";} cout << endl;}
template <typename T> void print(vector<vector<T>> &df) { for (auto& vec : df) { print(vec);}}
template <typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template <typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template <typename T> void SORT (T &v) {sort(v.begin(), v.end());}
template <typename T> void SORTR (T &v) {sort(v.begin(), v.end(), greater<>());}
template <typename T> T GCD(T x,T y) {return __gcd(x,y);}
template <typename T> T LCM(T x,T y) {return x/__gcd(x,y)*y;}
template <typename T> int SZ(T v) {return v.size();}
template <typename T> T PCNT(T x) {return __builtin_popcountll(x);}
template <typename T> T BIT(T x) {return 1LL<<(x);}
int INF = 2000000000;
long double PI = acosl(-1);
int MOD = 1000000007;

int op(int a, int b) { return max(a, b); }

int e() { return -1; }
int target;

bool f(int v) { return v < target; }

int32_t main() {
    chrono::system_clock::time_point start_time, end_time;
    start_time = chrono::system_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int ans = 0;
    
    int N, Q;
    cin >> N >> Q;
    VI A(N);
    REP(i,N) cin >> A[i];

    segtree<int, op, e> seg(A);
    

    REP(i,Q) {
        int T;
        cin >> T;
        if (T == 1) {
            int X,V;
            cin >> X >> V;
            X--;
            seg.set(X,V);
        }
        else if (T == 2) {
            int L, R;
            cin >> L >> R;
            L--;
            cout << seg.prod(L,R) << endl;
        }
        else {
            int P;
            cin >> P >> target;
            P--;
            cout << seg.max_right<f>(P) + 1 << endl;
        }
    }

    
    

    end_time = chrono::system_clock::now();
    assert(chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count() < 2000);
    return 0;
}

/*
cd ~/Desktop/Programming/AtCoder/contest/practice2/practice2_j && sh shellscripts/test_cpp.sh
cd ~/Desktop/Programming/AtCoder/contest/practice2/practice2_j && sh shellscripts/etest_cpp.sh
cd ~/Desktop/Programming/AtCoder/contest/practice2/practice2_j && sh shellscripts/submit_cpp.sh
*/
