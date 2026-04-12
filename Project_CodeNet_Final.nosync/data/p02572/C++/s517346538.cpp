
	
	#include <bits/stdc++.h>
	#include <cstdio>
	#include <cstring>
	#include <cmath>
	#include <cstring>
	#include <chrono>
	#include <complex>
	#define endl "\n"	
	typedef long long LL;
	#define ll long long int
	#define vi vector<int>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<int,int>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define mod2 998244353
	#define INFINITE 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define sz(v) ((ll)(v).size())
	#define mp(x,y) make_pair(x,y)
	#define mem(a,val) memset(a,val,sizeof(a))
	#define eb emplace_back
	#define pb push_back
	#define f first
	#define s second
	#define dbg(a) cout<<#a<<" --> "<<(a)<<"\n";
	#define forn(i,n) for (ll i=0; i<(n); ++i)
	#define fornd(i,n) for (ll i=(n)-1; i>=0; --i)	
	#define forab(i,a,b) for (ll i=(a); i<=(b); ++i)
	#define read(a) ll a; cin >> a;
	#define reads(s) string s; cin >> s;
	#define readb(a, b) ll a, b; cin >> a >> b;
	#define readc(a, b, c) ll a, b, c; cin >> a >> b >> c;
	#define readarr(a, n) int a[(n) + 1] = {}; forab(i, 0, (n-1)) {cin >> a[i];}
	#define readmat(a, n, m) int a[n + 1][m + 1] = {}; forab(i, 1, n) {forab(j, 1, m) cin >> a[i][j];}
	#define readv(A,n) vll A(n,0); forn(i,n) cin>>A[i]; 
	#define print(a) cout << a << endl;
	#define printarr(a, n) forab (i, 1, n) cout << a[i] << " "; cout << endl;
	#define printv(v) for (int i: v) cout << i << " "; cout << endl;
	#define printmat(a, n, m) forab(i, 1, n) {forab (j, 1, m) cout << a[i][j] << " "; cout << endl;}
	 
	#define INF (1e18+5)
	#define inf (1e9+5)
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };
	// 8-directions
	//int dx[]={1,1,1,0,0,-1,-1,-1};
	//int dy[]={-1,0,1,-1,1,-1,0,1};
	#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
	using namespace std;
	int begtime = clock();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	mt19937_64 rngb(chrono::steady_clock::now().time_since_epoch().count()); // can give negative values too
	bool isPowerOfTwo(int x) {
    return x && (!(x & (x - 1)));
	}
	int takemod(int x) {
    return (x % mod + mod) % mod;
	}
 
		ll power(ll a, ll b)	//a is base, b is exponent
		{
			if(b==0)
				return 1;
			if(b==1)
				return a;
			if(b%2 == 1)
				return (power(a,b-1)*a)%mod;
			ll q = power(a,b/2);
			return (q*q)%mod;
		}
 
	
	void solve()
	{
		ll n,ans=0;
		cin>>n;
		vll A(n);
		
		forn(i,n)
		{
			cin>>A[i];
		}
		vll pre(1,0);
		fornd(i,n)pre.pb(pre.back()+A[i]);
		forn(i,n)
		{
			//dbg(pre[n-i-1])
			ans=(ans%mod+((A[i]%mod)*(pre[n-i-1]%mod)))%mod;
		}
		
			
		cout<<ans<<endl;
	}
	int main()
	{	
		#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		#endif
		fast_io;
		int T=1;
		//cin>>T;
		// cin.ignore(); must be there when using getline(cin, s)
		while(T--)
		{
			solve();
		}
		
		return 0;
	}

	
	