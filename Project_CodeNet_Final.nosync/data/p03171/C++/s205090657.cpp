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

// macros
#define rep(i, a, b) for(int i=a; i<b; i++)
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define all(c) c.begin(), c.end()
#define tr(c, it) for(auto it=(c).begin(); it!=c.end(); it++)
#define pb push_back
#define mp make_pair
#define bitcount __builtin_popcount
#define ispresent(c, x) ((c).find(x) != (c).end())
#define watch(x) cout<< (#x) << " is " << (x) <<"\n";
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


// constants
const long double eps = 1e-9;
const int inf = 5e8;
const int modn = 1e9+7;
const int MAX = 4e3;

int n;
ll a[MAX];
ll psum[MAX];
ll dp[MAX][MAX][2];

ll solve(int i, int j, int p)
{
	if(i==j) return a[i];
	ll &memo=dp[i][j][p];
	if(memo!=-1) return memo;
	
	ll ans1=a[i]+psum[j]-psum[i]-solve(i+1, j, 1-p);
	ll ans2=a[j]+psum[j-1]-psum[i-1]-solve(i, j-1, 1-p);
	return memo=max(ans1, ans2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Your code here
    memset(dp, -1, sizeof(dp));
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		psum[i]=psum[i-1]+a[i];
	}
	
	ll x=solve(1, n, 0);
	ll y=psum[n]-x;
	cout<<x-y<<"\n";
    return 0;
}

