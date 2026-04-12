#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll a[60], p[60];

ll f(ll n, ll x) {
    if (n == 0) {
        if (x <= 0) return 0;
        return 1;
    } else if (x <= 1 + a[n-1]) {
        return f(n-1, x-1);
    } else {
        return p[n-1] + f(n-1, x - a[n-1] - 2) + 1;
    }
}

int main() {
    ll n, x;
    cin >> n >> x;

    a[0] = p[0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i] = 2 * a[i-1] + 3;
        p[i] = 2 * p[i-1] + 1;
    }

    cout << f(n, x) << endl;
}
