//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define y2 azdfsdgwre

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 1e7 + 123, MOD = 998244353;
int n, fact[N], rev[N];

int binpow(int x, int y) {
    int res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (ll)res * x % MOD;
        }
        x = (ll)x * x % MOD;
        y /= 2;
    }
    return res;
}

int c(int x, int y) {
    if (y > x) {
        return 0;
    }
    return ((ll)fact[x] * rev[y] % MOD) * rev[x - y] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    fact[0] = rev[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (ll)fact[i - 1] * i % MOD;
        rev[i] = (ll)rev[i - 1] * binpow(i, MOD - 2) % MOD;
    }
    cin >> n;
    int res = binpow(3, n);
    for (int i = n / 2 + 1; i <= n; i++) {
        res -= (ll)2 * binpow(2, n - i) * c(n, i) % MOD;
        if (res < 0) {
            res += MOD;
        }
    }
    cout << res;
}
