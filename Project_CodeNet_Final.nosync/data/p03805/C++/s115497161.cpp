/**
*	created: 11.09.2020 13:48:21
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
using ll = long long;
using P = pair<int,int>;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T &b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T &b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

signed main() {
    vector<P> to;
    int n, m; cin >> n >> m;
    rep(i,m) {
        int a, b; cin >> a >> b;
        a--; b--;
        to.push_back(P(min(a,b),max(a,b)));
    }
    vector<int> v;
    rep2(i,1,n) v.push_back(i);
    int t = 1;
    rep(i,n-1) t *= i + 1;
    sort(all(to));
    int cnt = 0;
    rep(i,t) {
        bool ok = true;
        if (!binary_search(all(to),P(0,v[0]))) ok = false;
        rep2(j,1,n-1) {
            int a = min(v[j-1],v[j]), b = max(v[j-1],v[j]);
            if (!binary_search(all(to),P(a,b))) ok = false;
        }
        if (ok) {
            cnt++;
        }
        next_permutation(all(v));
    }
    cout << cnt << endl;
    return 0;
}