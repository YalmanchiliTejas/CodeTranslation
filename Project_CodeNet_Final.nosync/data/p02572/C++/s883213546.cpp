#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,a,b) for(int i=a; i<=(b); ++i)
#define rep3(i,a,b) for(int i=a; i>=(b); --i)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define Dcout(a) cout << setprecision(20) << a << endl
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define fi first
#define se second
using Graph = vector<vector<ll>>;
const ll INF64 = (1LL << 60);
const ll INF = 1<<29;
const double pi=acos(-1.0);
/******************* debug ********************/
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
#define deb cout << "line : " << __LINE__ << " debug" << endl
template<typename T> void view(T e){cout << e << endl;}
template<typename T> void view(const vector<T>& v){
    for(const auto& e : v) cout << e << " ";
    cout << endl;}
template<typename T> void view(const vector<vector<T> >& vv){
    for(const auto& v : vv){ view(v); }}
/****** Template of some basic operations *****/
struct IoSetup {
    IoSetup() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(10);
        cerr << fixed << setprecision(10);
        }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
    os << p.first << " " << p.second;
    return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
    is >> p.first >> p.second;
    return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
    for(int i = 0; i < (int) v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
    for(T &in : v) is >> in;
    return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = ll >
vector< T > make_v(size_t a) {
    return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
    return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
    t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
    for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
    FixPoint(F &&f) : F(forward< F >(f)) {}

    template< typename... Args >
    decltype(auto) operator()(Args &&... args) const {
        return F::operator()(*this, forward< Args >(args)...);
    }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
    return FixPoint< F >{forward< F >(f)};
}
/*******************************************************/
//******************** Start coding! *******************/

const ll MOD = 1000000007;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    vector<ll> s(n);
    s[0] = a[0];
    for(int i=1; i<n; i++){
        s[i] += s[i-1] + a[i];
    }

    ll ans = 0;
    for(int i=1; i<n; i++){
        ans += a[i]*(s[i-1]%MOD);
        ans %= MOD;
    }

    cout << ans << endl;

}

