#include<bits/stdc++.h>
using namespace std;


// type definitions
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector< vi > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef complex<int> ci;
typedef complex<double> cd;
typedef complex<long double> cld;
typedef long double ld;

// macros
#define rep(i, a, b) for(int i=a; i<b; i++)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define all(c) c.begin(), c.end()
#define tr(c, it) for(auto it=(c).begin(); it!=c.end(); it++)
#define PB push_back
#define MP make_pair
#define bitcount __builtin_popcount
#define watch(x) cerr<< (#x) << " is " << (x) <<"\n";
#define sz(x) ((int)((x).size()))
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
#define pii2ll(p) ((ll)(p).first<<32 | (p).second)

// template functions
template <typename T>
inline void printV(vector<T>& a) { rep(i, 0, sz(a)) { cout<<a[i]<<" "; } cout<<"\n"; }
template <typename T>
inline void printV(vector<T>& a, int n) { rep(i, 0, n) { cout<<a[i]<<" "; } cout<<"\n"; }
template <typename T>
inline void printVV(vector<vector<T>>& a)
{
	rep(i, 0, sz(a)) {
		printV(a[i]);
	}
	cout<<"\n";
}

template <typename T>
inline void clearVV(vector<vector<T>>& a)
{
	for(auto& x:a) {
		x.clear();
	}
	a.clear();
}
template <typename T>
inline void assignVV(vector<vector<T>> &a, T val)
{
	for(int i=0; i<sz(a); i++) {
		for(int j=0; j<sz(a[i]); j++) {
			a[i][j]=val;
		}
	}
}

// random number generation
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// constants
const long double eps = LDBL_EPSILON;
const int inf = 5e8;
const int modn = 1e9+7;
const int MAX = 1e5;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
	int n;
	cin>>n;
	vector<int> h(n);
	for(int i=0; i<n; i++) {
		cin>>h[i];
	}
	int ans =1;
	int maxh=h[0];
	for(int i=1; i<n; i++) {
		if(h[i]>=maxh) {
			ans++;
			maxh=h[i];
		}
	}
	cout<<ans<<"\n";
    return 0;
}

