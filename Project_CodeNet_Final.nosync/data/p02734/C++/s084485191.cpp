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
const int modn = 998244353;
const int maxn = 2e5+3;

inline int add(int a, int b) { int ret=((ll)a+b)%modn; if(ret<0) ret+=modn; return ret; }
inline int mul(int a, int b) { int ret=((ll)a*b)%modn; if(ret<0) ret+=modn; return ret; }
template<typename... Args>
inline int add(int a, Args... args) { return add(a, add(args...)); }
template<typename... Args>
inline int mul(int a, Args... args) { return mul(a, mul(args...)); }
inline int addm(int a, int b, int MOD) { int ret=((ll)a+b)%MOD; if(ret<0) ret+=MOD; return ret; }
inline int mulm(int a, int b, int MOD) { int ret=((ll)a*b)%MOD; if(ret<0) ret+=MOD; return ret; }
inline int addm(int a, int b, int c, int MOD) { return addm(a, addm(b, c, MOD), MOD); }
inline int mulm(int a, int b, int c, int MOD) { return mulm(a, mulm(b, c, MOD), MOD); }

int po(int a, int b)
{
    int res=1;
    while(b>0) {
        if(b&1) res=mul(res, a);
        a=mul(a, a);
        b>>=1;
    }
    return res;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
    int n, S;
    cin>>n>>S;
    vi a(n);
    for(int i=0; i<n; i++) {
        cin>>a[i];
    }
    vvi dp(n, vi(S+1, -1));
    function<int(int, int)> solve = [&](int i, int s)
    {
        if(i==n) {
            return (int)0;
        }

        int &ans = dp[i][s];
        if(ans!=-1) return ans;

        ans = 0;
        if(s==a[i]) {
            ans = add(n-i, solve(i+1, s));
        }
        else if(s>=a[i]) {
            ans = add(solve(i+1, s-a[i]), solve(i+1, s));
        }
        else {
            ans = solve(i+1, s);
        }
        return ans;
    };
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = add(ans, solve(i, S));
    }
    cout << ans << "\n";
    return 0;
}

