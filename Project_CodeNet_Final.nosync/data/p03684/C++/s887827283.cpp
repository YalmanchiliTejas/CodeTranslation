#include<bits/stdc++.h>
using namespace std;

// macros
#define int long long 
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define all(c) c.begin(), c.end()
#define PB push_back
#define MP make_pair
#define bitcount __builtin_popcount
#define watch(x) cerr<< (#x) << " is " << (x) <<"\n";
#define sz(x) ((int)((x).size()))
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
#define pii2ll(p) ((ll)(p).first<<32 | (p).second)

// type definitions
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair<int, int> pii;
typedef long double ld;

// template functions
template < typename A, typename B >
ostream &operator << ( ostream& os, const pair< A, B > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "[";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}
template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "{";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}
template < typename A, typename B >
ostream &operator << ( ostream & os, const map< A, B > &v ) {
    os << "[";
    typename map< A, B >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " -> " << it -> second ;
    }
    return os << "]";
}
template<typename T>
T gcd(T a, T b) { if(a==0 or b==0) return a+b; return gcd(b, a%b) ; }
template<typename T>
T lcm(T a, T b) { if(a==0 or b==0) return 0; return a/gcd(a, b)*b; }

// random number generation
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// constants
const long double eps = LDBL_EPSILON;
const int inf = 1e15;
const int modn = 1e9+7;
const int maxn = 1e5+3;

int parent[maxn], siz[maxn];
int ans;

int find_parent(int u) {
    if(parent[u]==-1) return u;
    return parent[u] = find_parent(parent[u]);
}

void combine(int u, int v, int w) {
    u = find_parent(u), v = find_parent(v);
    if(u==v) return;

    if(siz[u] > siz[v]) swap(u, v);
    parent[u] = v;
    siz[v] += siz[u];
    ans += w;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
    int n;
    cin>>n;
    vector<array<int, 3> > a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i][0]>>a[i][1];
        a[i][2] = i;
    }
    sort(all(a), [&](array<int, 3> a1, array<int, 3> a2){
        return a1[0] < a2[0];
    });
    vector<array<int, 3> > edges;
    for(int i=0; i<n-1; i++) {
        int u = a[i][2], v = a[i+1][2], w = a[i+1][0] - a[i][0];
        edges.PB(array<int, 3>{w, u, v});
    }
    sort(all(a), [&](array<int, 3> a1, array<int, 3> a2) {
        return a1[1] < a2[1];
    });
    for(int i=0; i<n-1; i++) {
        int u = a[i][2], v = a[i+1][2], w = a[i+1][1] - a[i][1];
        edges.PB(array<int, 3>{w, u, v});
    }
    sort(all(edges), [&](array<int, 3> a1, array<int, 3> a2) {
        return a1[0] < a2[0];
    });
    memset(parent, -1, sizeof(parent));
    fill(siz, siz+maxn, 1);
    ans = 0;
    for(int i=0; i<sz(edges); i++) {
        int w = edges[i][0], u = edges[i][1], v = edges[i][2];
        combine(u, v, w);
    }
    cout << ans << "\n";
    return 0;
}

