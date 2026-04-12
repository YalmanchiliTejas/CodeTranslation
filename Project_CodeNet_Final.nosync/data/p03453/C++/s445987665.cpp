	
	// Problem : E - Avoiding Collision
	// Contest : AtCoder - AtCoder Regular Contest 090
	// URL : https://atcoder.jp/contests/arc090/tasks/arc090_c
	// Memory Limit : 256 MB
	// Time Limit : 2000 ms
	// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
	
	// author - chick_magnet® 
	
	#include<bits/stdc++.h>
	using namespace std;
	#pragma comment(linker, "/stack:200000000")
	#pragma GCC optimize("Ofast")
	#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
	#define ll long long
	#define int long long
	#define mod 1000000007 //998244353
	#define fast  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	#define f(i,n) for(ll i=0;i<n;i++)
	#define fore(i, a, b) for (ll i = (ll)(a); i <= (ll)(b); ++i)
	#define nl "\n"
	#define trace(x) cerr<<#x<<": "<<x<<" "<<endl
	#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
	#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
	#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
	#define cout1(a) cout<<a<<nl
	#define cout2(a,b) cout<<a<<" "<<b<<nl
	#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<nl
	#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<nl
	#define vcout(v,i) cout<<v[i].fi<<" "<<v[i].se<<nl
	#define x first
	#define y second
	#define vc vector
	#define pb push_back
	#define ar array
	#define all(a) (a).begin(), (a).end()
	#define ms(v,n,x) fill(v,v+n,x);
	#define init(c,a) memset(c,a,sizeof(c))
	#define pll pair<ll,ll>
	#define mll map<ll,ll>
	#define sll set<ll>
	#define vll vector<ll>
	#define vpll vector<pll>
	#define maxi(a,b,c) max(a,max(b,c))
	#define maxii(a,b,c,d) max(max(a,b),max(c,d))
	#define mini(a,b,c) min(a,min(b,c))
	#define md(a,b)  ((a%mod)*(b%mod)+mod)%mod 
	#define inf 9e15
	#define cases ll T;cin>>T;while(T--)
	#define BLOCK 500
	//const double PI = 3.141592653589793238460;
	template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
	template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
	typedef std::complex<double> Complex;
	typedef std::valarray<Complex> CArray;
	void __print(int x) {cerr << x;}
	void __print(long x) {cerr << x;}
	// void __print(long long x) {cerr << x;}
	void __print(unsigned x) {cerr << x;}
	void __print(unsigned long x) {cerr << x;}
	void __print(unsigned long long x) {cerr << x;}
	void __print(float x) {cerr << x;}
	void __print(double x) {cerr << x;}
	void __print(long double x) {cerr << x;}
	void __print(char x) {cerr << '\'' << x << '\'';}
	void __print(const char *x) {cerr << '\"' << x << '\"';}
	void __print(const string &x) {cerr << '\"' << x << '\"';}
	void __print(bool x) {cerr << (x ? "true" : "false");}
	
	template<typename T, typename V>
	void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
	template<typename T>
	void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
	void _print() {cerr << "]\n";}
	template <typename T, typename... V>
	void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
	#ifndef ONLINE_JUDGE
	#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
	#else
	#define debug(x...)
	#endif
	
	std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
	
	const int N=101010;
	
	
	ll n,m,s,t,d[N][2],dp[N][2];
	vpll g[N];
	ll mu(ll a,ll b){
		a%=mod;b%=mod;
		return (a*b)%mod;
	}
	void add(ll &a,ll b){
		a+=b;
		if(a>=mod)
		a-=mod;
	}
	
	void sub(ll &a,ll b){
		a-=b;
		if(a<0)
		a+=mod;
	}
	
	
	void dij(ll src,ll f){
		set<pll> q;
		fore(i,1,n)d[i][f]=inf;
		q.insert({0,src});
	
		d[src][f]=0;
		
		dp[src][f]=1;
		
		while(!q.empty()){
			ll u=(*q.begin()).y;
			q.erase(*q.begin());
			for(auto to:g[u]){
				ll v=to.x;
				ll w=to.y;
			
				
				if(d[v][f]>d[u][f]+w){
					q.erase({d[v][f],v});
					d[v][f]=d[u][f]+w;
					q.insert({d[v][f],v});
					dp[v][f]=dp[u][f];
						
				}
				else if(d[v][f]==d[u][f]+w){
					add(dp[v][f],dp[u][f]);
				}
		
				
				
				
			}	
			
		}
		
		
	}
	
	int32_t main()
	{
	    
		fast	
		cout << fixed << setprecision(12);
		cin>>n>>m>>s>>t;
		
		vc<pair<pll,ll>> ed;
		
		f(i,m){
			ll u,v,w;
			cin>>u>>v>>w;
			// debug(u,v);
			g[u].pb({v,w});
			g[v].pb({u,w});
			
			ed.pb({{u,v},w});
		}
		
		
		dij(s,0);
		dij(t,1);
		
		ll dis=d[s][1];
		
		ll ans=mu(dp[t][0],dp[s][1]);
	
		fore(i,1,n){
			
			if(d[i][0]==d[i][1] and d[i][0]==dis/2){
				
				ll x= mu(mu(dp[i][0], dp[i][0]), mu(dp[i][1], dp[i][1]));
				sub(ans,x);
				
			}
		}
		
		for(auto v:ed){	
		
				ll i=v.x.x;ll j=v.x.y;ll w=v.y;
				
				
				if(d[i][0]+d[j][1]+w==dis){
					if(d[i][0]<(dis/2) and d[j][1]<(dis/2)){
						ll x=mu(mu(dp[i][0],dp[j][1]),mu(dp[j][1],dp[i][0]));
						
						sub(ans,x);
						
					}
					
				}
				
				
				
				
				if(d[j][0]+d[i][1]+w==dis){
					if(d[j][0]<(dis/2) and d[i][1]<(dis/2)){
						ll x=mu(mu(dp[j][0],dp[i][1]),mu(dp[j][0],dp[i][1]));
						
						sub(ans,x);
						
					}
					
				}
				
		
		}
		
		cout<<ans<<nl;
	
	    
	
		return 0;
	    
	}