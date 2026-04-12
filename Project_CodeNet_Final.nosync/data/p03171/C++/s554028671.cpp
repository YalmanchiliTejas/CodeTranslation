#ifdef Dhiraj
    #include "D:/dhiraj/Programming/debug.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
    #define d(...) 11
    #define cerr if(0) cerr
#endif

// Macro --------------------------------------------------------------------

#define ll                  long long int
#define FOR(i, a, b, s)     for(ll i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define FOR1(b)             FOR(i, 0, b, 1)
#define FOR2(i, b)          FOR(i, 0, b, 1)
#define FOR3(i, a, b)       FOR(i, a, b, (a) <= (b) ? 1 :-1)
#define FOR4(i, a, b, s)    FOR(i, a, b, s)
#define GET5(a, b, c, d, e, ...) e
#define FORC(...)           GET5(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)
#define loop(...)           FORC(__VA_ARGS__)(__VA_ARGS__)
#define all(x)              x.begin(), x.end()
#define rall(x)             x.rbegin(), x.rend()
#define endl                '\n'

// Template -----------------------------------------------------------------

// multiple input
template <typename... T> 
inline void inp(T&... args) {
    ((cin >> args), ...);
}
// scan vector
template <typename T> 
inline istream& operator >>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// scan pair
template <typename T, typename U> 
inline istream& operator >>(istream &in, pair<T, U> &a) {
    in >> a.first >> a.second; 
    return in;
}

// Solve --------------------------------------------------------------------

const ll mx = 4000;
ll dp[mx][mx];

ll n;
vector<ll> a;

ll f(ll i, ll j)
{
    if(i > j || i < 0 || j < 0 || i >= n || j >= n) return 0;    
    if(dp[i][j] != -1) return dp[i][j];

    ll& ans = dp[i][j];
    ans = max(a[i] - f(i + 1, j), a[j] - f(i, j - 1));
    return ans;
}

void solve(int &T)
{
    cin >> n;
    a.resize(n);
    cin >> a;

    memset(dp, -1, sizeof(dp));
    cout << f(0, n - 1) << endl;
}

// Main ---------------------------------------------------------------------

int main()
{
    #ifdef Dhiraj
        freopen("D:/dhiraj/Programming/i1.txt", "r", stdin);
        freopen("D:/dhiraj/Programming/o1.txt", "w", stdout);
        // freopen("D:/dhiraj/Programming/e1.txt", "w", stderr);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    for(int i = 1; i <= t; i++) {
        cerr << "Case #" << i << "\n";
        solve(i);
    }
    return 0;
}