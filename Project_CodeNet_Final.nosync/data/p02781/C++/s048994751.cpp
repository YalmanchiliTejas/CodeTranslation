#include <bits/stdc++.h>

using namespace std;

// MACROS

#define ll long long
#define ull unsigned long long
#define ld long double

#define vi vector<int>
#define vll vector<ll>
#define vld vector<ld>
#define u_s unordered_set

#define pii pair<int,int>
#define pll pair<ll,ll>

#define FOR(i, n) for (ll (i) = 0; i < n; i++)
#define FORN(i, a, b) for (ll (i) = a; i < b; i++)
#define FORE(i, l) for (auto (i) : l)

#define pb push_back
#define pob pop_back
#define emp emplace
#define fi first
#define se second

#define all(n) (n).begin(), (n).end()
#define in(n) cin >> (n);
#define debug(n) cout << #n << ": " << n << '\n';

// FUNCTIONS

template< typename T >
inline T gcd(T a, T b) { if (b) return gcd(b, a % b); return a; }

template< typename T >
inline T ext_gcd(T a, T b, T & x, T & y) { if (a == 0) { x = 0; y = 1; return b; } T x1, y1; T g = ext_gcd(b % a, a, x1, y1); x = y1 - (b / a) * x1; y = x1; return g; }

ll f1(string n, ll N)
{
    if (N < 0) return 0;
    if (N == 0) return n[0] - '0';
    string x = "";
    x.resize(N);
    FOR(i, N) x[i] = n[i];
    return 9 + f1(x, N - 1);
}

ll f2(string n, ll N)
{
    if (N < 1) return 0;
    string x = "";
    x.resize(N);
    FOR(i, N) x[i] = '9';
    ll res1 = (n[0] - '0' - 1) * f1(x, N - 1) + f2(x, N - 1);
    bool found = false;
    x = "";
    FORN(i, 1, N + 1)
    {
        if (n[i] != '0' || found)
        {
            x += n[i];
            found = true;
        }
    }

    ll res2 = f1(x, (ll)x.size() - 1);
    return res1 + res2;
}
ll f3(string n, ll N)
{
    if (N < 2) return 0;
    string x = "";
    x.resize(N);
    FOR(i, N) x[i] = '9';
    ll res1 = (n[0] - '0' - 1) * f2(x, N - 1) + f3(x, N - 1);
    bool found = false;
    x = "";
    FORN(i, 1, N + 1)
    {
        if (n[i] != '0' || found)
        {
            x += n[i];
            found = true;
        }
    }

    ll res2 = f2(x, (ll)x.size() - 1);
    return res1 + res2;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);	
    //cout << setprecision(15);
    string n; ll k;
    cin >> n >> k;
    ll N = n.size() - 1;
    if (k == 1) cout << f1(n, N) << '\n';
    else if (k == 2) cout << f2(n, N) << '\n';
    else cout << f3(n, N) << '\n';
}

