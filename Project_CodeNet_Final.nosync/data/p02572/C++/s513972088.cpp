#include <iomanip>
#include <cmath>
#include <cstdio>
#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#define NDEBUG
#include <cassert>
#include <bitset>
using namespace std;

#define prv(a)            \
    for (auto x : a)      \
    {                     \
        cout << x << " "; \
    }                     \
    cout << '\n';
#define prvp(a)                                     \
    for (auto x : a)                                \
    {                                               \
        cout << x.first << " " << x.second << '\n'; \
    }                                               \
    cout << '\n';
#define ll long long
#define ld long double
#define INF pow(10, 10)
#define all(v) v.begin(), v.end()
#define bg begin()
#define ed end()
#define tr(it, v) for (auto it = v.bg; it != v.ed; it++)
#define f(a, b) for (ll i = a; i < b; i++)
#define fj(a, b) for (ll j = a; j < b; j++)
#define fb(b, a) for (ll i = b; i > a; i--)
#define dout(x) cout << x << '\n';
#define dout2(x, y) cout << x << " " << y << '\n';
#define dout3(x, y, z) cout << x << " " << y << " " << z << '\n';
#define pr1(x) cout << (x) << " ";
#define pr(x) cout << #x << " " << (x) << endl;
#define pr2(x, y) cout << #x << " " << (x) << "  " << #y << " " << (y) << endl;
#define pr3(x, y, z) cout << #x << " " << (x) << "  " << #y << " " << (y) << "  " << #z << " " << (z) << endl;
#define pp(x) cout << x.first << " " << x.second << endl;
ll min(ll a, ll b) {if(a < b) return a; else return b;} 
ll max(ll a, ll b) {if(a < b) return b; else return a;} 
ll min3(ll a, ll b, ll c) {return min(a,min(b,c));} 
ll max3(ll a, ll b, ll c) {return max(a,max(b,c));} 

ll NC=100; 
ll N = 1e9+7;
const ll S = 1e5 + 7;

ll mod(ll n);
ll gcd(ll a, ll b); 
ll modM(ll n, ll m);
ll modA(ll n, ll m);
ll modS(ll n, ll m);
ll power(ll a, ll b);
void ipgraph(ll n, ll m);
//==============================================================================================

vector<vector<ll>> v;
vector<bool> vis;

void solve()
{    
    ll n;
    cin >> n;
    vector<ll> a(n), sum(n+1); 
    f(0,n) cin >> a[i], sum[i+1]=modA(sum[i],a[i]); 
    //prv(a) prv(sum) 
    ll ans=0; 
    f(0, n-1)
    {
        ans=modA(ans,modM(a[i],(sum[n]-sum[i+1]))); 
    }
    cout << ans; 

}   

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("/Users/aturgupta/Desktop/CP/input.txt", "r", stdin);
    freopen("/Users/aturgupta/Desktop/CP/output.txt", "w", stdout);
#endif

    ll t;
    //cin >> t;
    t=1; 
    while (t--) solve();
    cerr << endl << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}

void ipgraph(ll n, ll m)
{
    v.assign(n, {});
    vis.assign(n, 0);
    ll x, y;
    f(0, m)
    {
        cin >> x >> y;
        x--, y--;
        v[y].push_back(x);
        v[x].push_back(y); 
    }
}

ll gcd(ll a, ll b)
{
    if (b > a) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll power(ll a, ll b)
{
    if (b == 0) return 1;
    ll c = power(a, b / 2);
    if (b % 2 == 0) return modM(c,c);
    else return modM(modM(c,c),a);
}

ll mod(ll n) {return (n % N + N) % N; }
ll modM(ll n, ll m) { return ((n % N * m % N) + N) % N; }
ll modA(ll n, ll m) { return ((n % N + m % N) + N) % N; }
ll modS(ll n, ll m) { return ((n % N - m % N) + N) % N; }
