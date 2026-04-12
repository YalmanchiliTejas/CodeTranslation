/*
**   Contest : AtCoder Beginner Contest 177
**   Problem : C - Sum of product of pairs
**
**    Author : Dhiraj Govindvira
**      Date : 29-Aug-2020 ~ Saturday
**      Time : 07:20:43 PM
*/

#if __has_include("D:/dhiraj/Programming/debug.h")
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
    ((cin>>args), ...);
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

const ll Mod = 1e9 + 7;
inline ll md(ll x, ll M = Mod)
{
    x %= M;
    return ((x < 0) ? (x + M) : x);
}

void solve(int &T)
{
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    cin >> a;

    vector<ll> suf(n, 0);
    ll sm = 0;
    loop(i, n) {
        sm += a[n - i - 1];
        suf[n - i - 1] = sm;
    }
    d(suf);

    ll ans = 0;
    loop(i, n - 1) {
        ans = md(ans + md(a[i] * md(suf[i + 1])));
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