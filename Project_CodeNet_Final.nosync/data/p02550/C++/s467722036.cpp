/*
**    author : dhiraj govindvira
**      date : 20-Sep-2020 ~ Sunday
**      time : 10:40:40 AM
*/

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
#define all(x)              (x).begin(), (x).end()
#define rall(x)             (x).rbegin(), (x).rend()
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


ll Mod = 1e9 + 7;
inline ll md(ll x, ll M = Mod)
{
    x %= M;
    return ((x < 0) ? (x + M) : x);
}
ll power(ll x, ll y, ll p = Mod) 
{
    ll res = 1;
    bool of = true;
    if(of) x = x % p;
    while(y > 0)
    { 
        if(y & 1)
        {
            if(of) res = (res * x) % p;
            else res *= x;
        }
        if(of) x = (x * x) % p;
        else x *= x;
        y >>= 1;
    }
    if(res < 0) res += of * p;
    return res;
}

void solve(int &T)
{
    ll n, x, m;
    cin >> n >> x >> m;

    Mod = m;
    ll ans = 0;

    vector<ll> vis(m + 1, 0);
    while(!vis[x] and n > 0)
    {
        n--;
        vis[x]++;
        ans += x;
        x = power(x, 2);
    }

    if(n == 0) {
        cout << ans << endl;
        return;
    }

    ll sm = 0, len = 0;
    while(vis[x] != 2)
    {
        len++;
        vis[x]++;
        sm += x;
        x = power(x, 2);
    }
    d(len, sm);
    ans += (sm * (n / len));

    n %= len;
    while(n > 0) {
        n--;
        ans += x;
        x = power(x, 2);
    }
    cout << ans << endl;
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