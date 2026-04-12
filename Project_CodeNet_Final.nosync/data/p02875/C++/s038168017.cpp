#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20);
#define int long long
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
template<class T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<class T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
#define _rev(i, n) revi(i, n, 0)
#define revi(i, a, b) for(int i = (int)(a - 1); i >= (int)(b); i--)
#define rev(...) _overload(__VA_ARGS__, revi, _rev)(__VA_ARGS__)
#define each(i, n) for(auto&& i: n)
const int INF = 1e18, MOD = 998244353;
int modpow(int a, int n){
    if(n < 1) return 1;
    return modpow(a * a % MOD, n / 2) * ((n % 2) ? a : 1) % MOD;
}
int modinv(int a){
    return modpow(a, MOD - 2);
}
int modfact(int a){
    if(a < 2) return 1;
    return a * modfact(a - 1) % MOD;
}
signed main() {
    INCANT;
    int n, fac, inv[11111111], res, tmp = 0, cnt = 1;
    cin>>n;
    res = modpow(3, n);
    fac = modfact(n);
    inv[n] = modinv(fac);
    rev(i, n){
        inv[i] = inv[i + 1] * (i + 1);
        inv[i] %= MOD;
    }
    rep(i, n / 2){
        tmp += inv[i] * inv[n - i] % MOD * cnt % MOD;
        tmp %= MOD;
        cnt *= 2;
        cnt %= MOD;
    }
    tmp = tmp * 2 * fac % MOD;
    cout<<(res - tmp + MOD) % MOD<<endl;
}
