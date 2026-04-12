#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define frn(i,a,b) for(ll i=a;i<b;i++)
#define forn(i,a,b) for(ll i=a;i<=b;i++)
#define frt(i,a,b) for(auto it=a;it!=b;it++)
#define MP make_pair
#define F first
#define S second
#define PB push_back
#define SQ(a) (a)*(a)
#define SUM(n) ((n)*(n+1))/2
#define SqSUM(n) ((n)*(n+1)*(2*n+1))/2
#define GMSUM(a,r,n) (a*pow(r,n)-a)/(r-1)
#define ciel(x, y) (((x) / (y)) + ((x) % (y) != 0))
#define tc(tt) \
    int tt;    \
    cin >> tt; \
    for (int _tt = 0; _tt < tt; _tt++)
#define input(v,n) for(ll i = 0 ; i<n ; i++) cin>>v[i]
#define output(v,n) for(ll i = 0 ; i<n ; i++) cout<<v[i]<<" "
#define endl '\n'
#define cout_p(x, p) cout << fixed << setprecision((p)) << x << endl
#define dbg(x) cerr << #x << "is" << (x) << endl
#define leadzero(a) __builtin_clz(a)      // count leading zeroes
#define trailzero(a) __builtin_ctz(a)     // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
const long long int md = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<vector<ll, ll> > vvi;
    // typedef bitset<5> bst;
typedef priority_queue<int, vector<int>, greater<int>> min_heap;
typedef priority_queue<int, vector<int>> max_heap;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
    indexed_set;
const ll MAX = LONG_MAX;
const ll lrg = 1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,m;
    cin>>n>>m;
    if(m!=n)
        cout<<"No";
    else if(m==n && m>=0)
        cout<<"Yes";
    return 0;
}