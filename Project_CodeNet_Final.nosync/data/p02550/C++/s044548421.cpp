#include <bits/stdc++.h>
using namespace std;
//#define ACL
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


int32_t main() {
    chrono::system_clock::time_point start_time, end_time;
    start_time = chrono::system_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);
    int ans = 0, res = 0;
    
    int N, X, M;
    cin >> N >> X >> M;
    map<int,int> mp;
    int A = X, ind1 = 0, ind2 = 0, same;
    while (mp[A] == 0) {
        mp[A] = 1;
        A = A*A % M;
        ind2++;
    }
    same = A;
    A = X;
    while (A != same) {
        A = A*A % M;
        ind1++;
    }
    int T = ind2 - ind1;
    A = X;
    REP(i,ind1) {
        ans += A;
        A = A*A % M;
    }
    A = same;
    FOR(i, ind1, ind2) {
        res += A;
        A = A*A % M;
    }
    ans += (N - ind1)/T*res;
    A = same;
    REP(i,(N - ind1)%T) {
        ans += A;
        A = A*A % M;
    }
    cout << ans << endl;

    
    



    end_time = chrono::system_clock::now();
    assert(chrono::duration_cast<chrono::milliseconds>(end_time-start_time).count() < 2500);
    return 0;
}

/*
cd ~/Desktop/Programming/AtCoder/contest/abc179/abc179_e && sh shellscripts/test_cpp.sh
cd ~/Desktop/Programming/AtCoder/contest/abc179/abc179_e && sh shellscripts/etest_cpp.sh
cd ~/Desktop/Programming/AtCoder/contest/abc179/abc179_e && sh shellscripts/submit_cpp.sh
*/
