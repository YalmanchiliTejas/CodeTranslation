// ooooo      ooo                     
// `888b.     `8'                     
//  8 `88b.    8   .ooooo.   .oooo.   
//  8   `88b.  8  d88' `88b `P  )88b  
//  8     `88b.8  888   888  .oP"888  
//  8       `888  888   888 d8(  888  
// o8o        `8  `Y8bod8P' `Y888""8o 
// C++ Conpetitive Programming Template 
// Ver 2.4 (codename: Noa)
// Last Modified : 2019-06-10
// Created       : 2019-05-25
// Auther        : shirataki3
#include <bits/stdc++.h>
using namespace std;
// typename alias
template <class T> using vec = vector<T>;
template <class T> using vvec = vec<vec<T> >;
template <class T, class U> using vep = vec<pair<T,U> >;
template <class T> using PQ = priority_queue<T>;
using ll = long long;
using vll = vec<ll>;
using pll = pair<ll, ll>;
using vpll = vec<pll>;
using str = string;
// きけん
//#define int ll
#define bits(x) (1LL << (n))

// const
static const long long INF = 1LL<<59;
static const int iINF = 1LL<<30;
static const double dINF = 1e290;
static const long long MOD = (ll)1e9+7;
static const double PI = 3.14159265358979323846;

// accelerate stdin, stdout
#define endl "\n"
#define presolve(n) ios_base::sync_with_stdio(false);cin.tie(NULL);cout.setf(ios::fixed);cout.precision(n);
// repeat macro
#define __ov3(_1, _2, _3, name, ...) name
#define REP(i, n) for(ll (i)=0;(i)<(n);(i)++)
#define FOR(i, a, b) for(ll (i)=(a);(i)<=(b);i++)
#define rFOR(i, a, b) for(ll (i)=(b);(i)>=(a);i--)
#define rep(...) __ov3(__VA_ARGS__, FOR, REP,)(__VA_ARGS__)
// vector macro
#define rng(v) (v).begin(), (v).end()
#define ASC(v) sort(rng(v))
#define DESC(v) sort((v).rbegin(), (v).rend())
#define INV(v) reverse(rng(v))
#define FOLDL(src, dst, lambda) partial_sum(rng(src), (dst).begin(), lambda)
#define FOLDR(src, dst, lambda) INV(src);partial_sum(rng(src), (dst).begin(), lambda);INV(dst)
#define CUMSUML(src, dst) FOLDL(src, dst, [](auto a, auto b) {return a+b;})
#define CUMSUMR(src, dst) FOLDR(src, dst, [](auto a, auto b) {return a+b;})
#define ACCUM(v, d0, lambda) accumulate(rng(v), d0, lambda)
#define SUM(v, d0) ACCUM(v, d0, [](auto a, auto b) {return a+b;})
#define ERASE(v, i) v.erase(v.begin() + i)
#define UNIQ(v) ASC(v);v.erase(unique(v.begin(), v.end()), v.end())
template <typename T> T min(vec<T> v) {return *min_element(rng(v));}
template <typename T> T max(vec<T> v) {return *max_element(rng(v));}

template <typename T> inline bool chmin(T& a, const T& b) {if(a > b) {a = b;return 1;}return 0;}  
template <typename T> inline bool chmax(T& a, const T& b) {if(a < b) {a = b;return 1;}return 0;}


// io helper
template <typename T>void debug(T t) {cerr << t << endl;}
template <typename T, typename ...Args>void debug(T t, Args ...args) {cerr << t << " ";debug(args...);}
template <typename T>void out(T t) {cout << t << endl;}
template <typename T, typename ...Args>void out(T t, Args ...args) {cout << t << " ";out(args...);}
template <typename T>istream& operator>>(istream &is, vec<T> &v) {for(auto &a:v) is >> a; return is;}
template <typename T>ostream& operator<<(ostream &os, vec<T> &v) {os << "[";REP(i, v.size() - 1) os << v[i] <<", "; os << v[v.size()-1]<<"]";return os;}
template <typename T, typename U>ostream& operator<<(ostream &os, pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")";return os;}
template <size_t N, typename T>ostream& operator<<(ostream &os, array<T, N> &v) {os << "[";REP(i, N - 1) os << v[i] <<", "; os << v[N-1]<<"]";return os;}
template <typename T, typename U>ostream& operator<<(ostream &os, map<T, U> &mp) {os << "{ ";for(auto &p:mp) os << p.first << ": " << p.second << ", "; os << "}";return os;}

void solve() {
    ll N;
    cin >> N;
    vpll vp(N);
    rep(i, N) {
        ll t;
        cin >> t;
        vp[i] = {t, i};
    }
    ASC(vp);
    vll ans(N);
    rep(i, N) {
        ans[vp[i].second] = vp[N / 2 - (i >= N / 2 ? 1 : 0)].first;
    }
    rep(i, N) {
        out(ans[i]);
    }
}

signed main() {
    presolve(20);
    solve();
    return 0;
}