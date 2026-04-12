#include <bits/stdc++.h>
using namespace std;

#define sz(a) int((a).size())
#define all(c) c.begin(), c.end()
#define ll long long
#define pb push_back
#define zoom                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pl pair<ll, ll>
#define MOD 1000000007
#define endl "\n"
#define ff first
#define ss second
#define trace1(x) cerr << #x << ": " << x << endl
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define trace3(x, y, z) cerr << #x << ":" << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
#define trace5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl
#define trace(v)                                   \
    for (auto it = v.begin(); it != v.end(); it++) \
        cerr << *it << " ";                        \
    cerr << endl;
#define tr(container, it) \
    for (typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpi;
typedef vector<pll> vpl;
typedef vector<vi> vvi;

void solve()
{
    int x;
    cin>>x;

    if(x>=30)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main()
{
    zoom;
    ll t=1;
    //cin >> t;

    while (t--)
    {
        solve();
    }
}