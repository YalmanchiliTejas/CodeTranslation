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
const int maxn = 2e5+3;

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
    vector<vector<pii > > adj(n);
    for(int i=0; i<n-1; i++) {
        int u = a[i][2], v = a[i+1][2], w = a[i+1][0] - a[i][0];
        adj[u].PB(MP(v, w));
        adj[v].PB(MP(u, w));
    }
    sort(all(a), [&](array<int, 3> a1, array<int, 3> a2) {
        return a1[1] < a2[1];
    });
    for(int i=0; i<n-1; i++) {
        int u = a[i][2], v = a[i+1][2], w = a[i+1][1] - a[i][1];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    priority_queue<pii, vector<pii>, greater<pii> > q;
    q.push(MP(0, 0));
    vi dist(n, inf);
    dist[0] = 0;
    vi marked(n);
    int ans = 0;
    while(!q.empty()) {
        pii p = q.top();
        q.pop();
        int u = p.second, w = p.first;
        if(marked[u]) continue;
        marked[u] = 1;
        ans += w;
        for(auto p2 : adj[u]) {
            int v = p2.first, w2 = p2.second;
            if(marked[v]) continue;
            if(w2 < dist[v]) {
                dist[v] = w2;
                q.push(MP(w2, v));
            } 
        }
    }
    cout << ans << "\n";
    return 0;
}

