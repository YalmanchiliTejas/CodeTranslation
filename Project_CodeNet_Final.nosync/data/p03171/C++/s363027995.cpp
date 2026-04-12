#include <bits/stdc++.h>
using namespace std;
// #define LOCAL // 提出時はコメントアウト

typedef long long ll;
const double EPS = 1e-9;
typedef vector<ll> vecl;
typedef pair<ll, ll> pairl;

template<typename T, typename U>
using mapv = map<T,vector<U>>;

#define ALL(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define contains(S,x) find(ALL(S),x) != S.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> vector<vector<T>> genarr(ll n, ll m, T init) { return vector<vector<T>>(n,vector<T>(m,init)); }

///// For Debug

#define repi(itr, ds) for (auto itr = ds.begin(); itr != ds.end(); itr++)
// vector
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec) is >> x;
    return is;
}
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, pair<T, U> &pair_var) {
    os << "(" << pair_var.first << ", " << pair_var.second << ")";
    return os;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
    os << "{";
    for (int i = 0; i < vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}
// map
template <typename T, typename U>
ostream &operator<<(ostream &os, map<T, U> &map_var) {
    os << "{";
    repi(itr, map_var) {
        os << *itr;
        itr++;
        if (itr != map_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
// set
template <typename T>
ostream &operator<<(ostream &os, set<T> &set_var) {
    os << "{";
    repi(itr, set_var) {
        os << *itr;
        itr++;
        if (itr != set_var.end()) os << ", ";
        itr--;
    }
    os << "}";
    return os;
}
 
#define DUMPOUT cerr
 
void dump_func() {
    DUMPOUT << endl;
}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    DUMPOUT << head;
    if (sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

#define DEBUG_

#ifndef LOCAL
#undef DEBUG_
#endif

#ifdef DEBUG_

#define DEB
#define dump(...)                                                              \
    DUMPOUT << "  " << string(#__VA_ARGS__) << ": "                            \
            << "[" << to_string(__LINE__) << ":" << __FUNCTION__ << "]"        \
            << endl                                                            \
            << "    ",                                                         \
        dump_func(__VA_ARGS__)
#else
#define DEB if (false)
#define dump(...)

#endif

//////////

const ll INF = 1e18;
ll N;
vecl A;
auto DP = genarr(4000,4000,INF);

ll dp(ll i,ll j) { // dp[i][j]: [i,j)区間内で操作したときのmin{X-Y} 
    if (i==j || i>=N) return 0;
    
    ll &ans = DP[i][j];
    if(ans != INF) return ans;

    bool first = (N-(i+j)) % 2 == 0;
    if (first) ans = max(dp(i+1,j)+A[i],dp(i,j-1)+A[j-1]);
    else ans = min(dp(i+1,j)-A[i],dp(i,j-1)-A[j-1]);

    return ans;
}

int main() {
    #ifdef LOCAL
    ifstream in("../../Atcoder/input.txt");
    cin.rdbuf(in.rdbuf());
    #endif


    cin>>N;

    A = vecl(N);
    rep(i,N) {
        cin>>A[i];
    }

    cout << dp(0,N) << endl;

    return 0;
}
