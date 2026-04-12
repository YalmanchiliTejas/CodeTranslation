#include <bits/stdc++.h>
#define _itr ::iterator
#define forn(i, x, y) for (ll i = x; i < y; ++i)
#define ford(i, x, y) for (ll i = x; i > y; --i)
#define forne(i, x, y) for (ll i = x; i <= y; ++i)
#define forde(i, x, y) for (ll i = x; i >= y; --i)
#define rd(x) cin >> x; cin.ignore();
#define rdstr(x) getline(cin, x);
#define rdarr(x, y) for (ll i = 0; i < y; ++i) cin >> x[i];
#define rdmtr(x, y, z) for (ll i = 0; i < y; ++i) for (ll j = 0; j < z; ++j) cin >> x[i][j];
#define pb push_back

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef long double ld;

const ll MaxN = 2e5 + 7;
const ll MaxM = 5e3 + 7;
const ll MDL = 1e9 + 7;
const ll INF = 1e18 + 7;

typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef ll arr[MaxN];

ll REPIT = 1;

const bool MQ = false;

ll s(ll a, ll b){ return ((a % MDL) + (b % MDL)) % MDL; }
ll m(ll a, ll b){ return ((a % MDL) * (b % MDL)) % MDL; }

ll n;
arr so;

void Solve()
{
    cin >> n; rdarr(so, n);
    ll res = 0, sum = so[0];
    forn(i, 1, n)
    {
        res = s(res, m(sum, so[i]));
        sum = s(sum, so[i]);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    #ifdef OFFLINE
    freopen("input.inp", "r", stdin);
    #endif
    if (MQ == true)
    {
        rd(REPIT);
    }
    while (REPIT--) Solve();
    cout.flush();
    #ifdef OFFLINE
    fclose(stdin);
    #endif
}
