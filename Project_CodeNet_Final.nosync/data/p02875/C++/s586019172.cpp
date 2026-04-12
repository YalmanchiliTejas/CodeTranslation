#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define INF  (1<<30)
#define INFL (1LL<<60)
#define EPS ((ld)(1e-9))
 
#define sz(x) ((int)(x).size())
#define setz(x) memset(x, 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define rep(i, e) for (int i = 0, _##i = (e); i < _##i; i++)
#define repp(i, s, e) for (int i = (s), _##i = (e); i < _##i; i++)
#define repr(i, s, e) for (int i = (s)-1, _##i = (e); i >= _##i; i--)
#define repi(i, x) for (auto &i : (x))
#define ARR(...) vector<int>({__VA_ARGS__})
#define ARS(...) vector<string>({__VA_ARGS__})
 
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef complex<double> base;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const pair<T, V> pai) { 
    return os << '(' << pai.first << ' ' << pai.second << ')';
}
 
template<typename T>
ostream &operator<<(ostream &os, const vector<T> v) {
    cout << '[';
    for (auto p : v) cout << p << ",";
    cout << "]";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const set<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
template<typename T, typename V>
ostream &operator<<(ostream &os, const map<T, V> v) {
    cout << "{";
    for (auto p : v) cout << p << ",";
    cout << "}";
    return os;
}
 
#ifdef ONLINE_JUDGE
#define debug(...) 0
#define endl '\n'
#else
#define debug(...) cout << " [-] ", _dbg(#__VA_ARGS__, __VA_ARGS__)
template<class TH> void _dbg(const char *sdbg, TH h){ cout << sdbg << '=' << h << endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
    while(*sdbg != ',') cout << *sdbg++;
    cout << '=' << (h) << ','; 
    _dbg(sdbg+1, a...);
}
#endif
 
template<typename T> void get_max(T &a, T b) {a = max(a, b);}
template<typename T> void get_min(T &a, T b) {a = min(a, b);}

constexpr ll MOD = 998244353;

int N;
ll fact[5000001] = {1};
ll invf[5000001] = {1};
ll ccom[5000002];
ll csum[5000002];

ll comb(ll a, ll b) {return fact[a]*invf[b]%MOD*invf[a-b]%MOD;}
ll mpow(ll a, ll b){
    ll res = 1;
    for (; b; b >>= 1) {
        if (b&1) res = res*a%MOD;
        a = a*a%MOD;
    }
    return res;
}
ll inv(ll v) {return mpow(v, MOD-2);}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;
    repp(i, 1, N/2+1) fact[i] = fact[i-1]*i%MOD;
    invf[N/2] = inv(fact[N/2]);
    repr(i, N/2, 1) invf[i] = invf[i+1]*(i+1)%MOD;
    rep(i, N/2+1) ccom[i] = comb(N/2, i);
    repr(i, N/2+1, 0) csum[i] = (csum[i+1]+ccom[i]*mpow(2, N/2-i))%MOD;

    ll res = mpow(3, N);
    repp(i, 1, N/2+1) {
        res -= ccom[i]*csum[N/2+1-i]%MOD*mpow(2, N/2-i+1);
        res = (res%MOD+MOD)%MOD;
    }

    cout << res << endl;
}