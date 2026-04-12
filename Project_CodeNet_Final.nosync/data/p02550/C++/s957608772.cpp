/**
*	created: 19.09.2020 22:04:08
**/
#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using bint = boost::multiprecision::cpp_int;
using namespace std;
// #define endl '\n'
#define int long long
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rrep(i,n) for (int i = (int)(n - 1); i >= 0; i--)
#define rep2(i,s,n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pcnt(bit) __builtin_popcountll(bit)
using ll = long long;
using P = pair<int,int>;
const long double pi = acos(-1.0);
const int MAX = 1000010;
const int INF = 1ll << 60;
const int MOD = 1000000007;
// const int MOD = 998244353;
template<typename T> inline bool chmax(T &a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T> inline bool chmin(T &a, T b) {if (b < a) {a = b; return 1;} return 0;}
inline void print(P a) {cout << a.first << " " << a.second << endl;}
template<typename T> T pow(T a, ll n) {T r(1); while(n) {if (n & 1) r *= a; a *= a; n >>= 1;} return r;}
struct faster_io {faster_io() {cin.tie(0); ios_base::sync_with_stdio(false);}} faster_io_;

signed main() {
    int n, x, m; cin >> n >> x >> m;
    map<int,int> mp;
    vector<int> v;
    int a = x;
    int t;
    rep(i,m+1) {
        mp[a]++;
        if (mp[a] > 1) {
            t = a;
            break;
        }
        v.push_back(a);
        a = (a * a) % m;
    }
    int st;
    rep(i,v.size()) if (v[i] == t) st = i;
    int rsum = 0;
    rep2(i,st,v.size()) rsum += v[i];
    int fsum = 0;
    rep(i,st) fsum += v[i];
    if (n <= v.size()) {
        int ans = 0;
        rep(i,n) ans += v[i];
        cout << ans << endl;
    }
    else {
        int res = n - st;
        int tim = res / (v.size()-st);
        int lsum = 0;
        rep2(i,st,st + (res % (v.size()-st))) lsum += v[i];
        cout << fsum + rsum * tim + lsum << endl;
    }
    return 0;
}