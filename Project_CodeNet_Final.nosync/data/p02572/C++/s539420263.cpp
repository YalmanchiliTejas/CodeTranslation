#include <bits/stdc++.h>
using namespace std;

#define trav(a, A) for (auto & a : A)
#define f first
#define s second

typedef long long ll;

const ll MOD = 1e+9+7;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const ll MAXN = 1e+5+7;

 
 
template <typename T>
T extGcd(T a, T b, T& x, T& y) {
    if (b == 0) {
        x = 1; y = 0; return a;
    }
    else {
        T g = extGcd(b, a % b, y, x);
        y -= a / b * x; return g;
    }
}
 
template <typename T>
T modInv(T a, T m) {
    T x, y;
    extGcd(a, m, x, y);
    return (x % m + m) % m;
}
 
template <typename T>
T modDiv(T a, T b, T m) {
    return ((a % m) * modInv(b, m)) % m;
}
 
template<typename T>
T modMul(T a, T b, T m) {
	T x = 0, y = a % m;
	while (b > 0) {
		if (b % 2 == 1) x = (x + y) % m;
		y = (y * 2) % m; b /= 2;
	}
	return x % m;
}
 
template<typename T>
T modExp(T a, T b, T m) {
    if (b == 0) return (T)1;
    T c = modExp(a, b / 2, m);
    c = (c * c) % m;
    if (b % 2 != 0) c = (c*a) % m;
    return c;
}
 

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0, eq = 0;
    for (auto &b: a) cin >> b, sum += b, sum %= MOD, eq += (b*b)%MOD, eq %= MOD;
    ll ans = ((sum*sum) % MOD) - eq;
    ans += MOD;
    ans %= MOD;
    ans = modDiv(ans, 2ll, MOD);
    cout << (ans+MOD) % MOD << '\n';
}

int main ()
{
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	ll i, j, n;
	int t = 1; //cin >> t;
	while(t--) solve();
	return 0;
}

