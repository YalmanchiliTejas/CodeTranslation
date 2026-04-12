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
typedef vector<pii> vpii;
typedef long double ld;

// template functions
template < typename A, typename B >
ostream& operator << ( ostream& os, const pair< A, B > & p ) {
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
template <typename T>
inline void printV(vector<T>& a, int n) { for(int i=0; i<n; i++) { cerr<<a[i]<<" "; } cerr<<"\n"; }
template <typename T>
inline void printVV(vector<vector<T>>& a) { for(int i=0; i<sz(a); i++) { cerr<<a[i]<<"\n"; } cerr<<"\n"; }
template <typename T>
inline void clearVV(vector<vector<T>>& a) { for(auto &x : a) { x.clear(); } a.clear(); }
template <typename T>
inline void assignVV(vector<vector<T>> &a, T val) { for(int i=0; i<sz(a); i++) { a[i].assign(sz(a[i]), val); } }
template<typename T>
T gcd(T a, T b) { if(a==0 or b==0) return a+b; return gcd(b, a%b) ; }

// random number generation
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// constants
const long double eps = LDBL_EPSILON;
const int inf = 5e8;
const int modn = 1e9+7;
const int MAX = 1e5;


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
	int n;
	cin>>n;
	multiset<int> ans;
	vi a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(sz(ans)==0) {
			ans.insert(a[i]);
			continue;
		}
		auto it = ans.lower_bound(a[i]);
		if(it!=ans.end()) {
			if(it==ans.begin()) {
				ans.insert(a[i]);
				continue;
			}
			it--;
			ans.erase(it);
			ans.insert(a[i]);
			continue;
		}
		it--;
		ans.erase(it);
		ans.insert(a[i]);
	}
	cout<<sz(ans)<<"\n";
    return 0;
}

