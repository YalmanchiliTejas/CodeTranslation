#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<typename T> void view(T cont) {std::cout << cont << std::endl;}
template<typename T> void view(T* cont, ll sz) {rep(i, sz) std::cout << cont[i] << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<T>& v) {for (const auto& f: v) std::cout << f << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v: vv) {view(v);}}
const long long INF = 1LL<<60;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const ll MAX_N = 52;
const ll MAX_X = 1e+13;

ll N, X;
vector<ll> a(MAX_N);
vector<ll> p(MAX_N);

ll solve(ll n, ll x) {
    if (n == 0) {
        if (x <= 0) return 0;
        else return 1;
    }
    else if (x <= 1 + a[n - 1]) {
        return solve(n - 1, x - 1);
    }
    else
        return p[n - 1] + 1 + solve(n - 1, x - 2 - a[n - 1]);
}

int main(){
    cin >> N >> X;
    a[0] = 1;
    p[0] = 1;
    rep(i, N) {
        a[i + 1] = 2 * a[i] + 3;
        p[i + 1] = 2 * p[i] + 1;
    }
    // view(a);
    // view(p);
    ll ans = solve(N, X);
    cout << ans << endl;
}