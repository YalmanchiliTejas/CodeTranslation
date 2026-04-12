#include <bits/stdc++.h>
 
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define repb(i, r, l) for (int i = r; i >= l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define ret(a) {cout << a; exit(0);}
 
using namespace std;                                                                                  
 
mt19937 mrand(random_device{}()); 
const ll mod = 1e9 + 7;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
 
typedef pair < int , int > pii ;                                            
typedef pair < long long  , long long > pll ;
 
const int N = 3e5 + 123;
 
int n, m, k;
vector < pii > gr[N];
int a[N];
int dp1[N] , cnt1[N], dp2[N], cnt2[N] , w[N] , v[N] , u[N];
 
main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int s , t;
	cin >> n >> m >> s >> t;
 
	rep(i , 1 , n)
		dp1[i] = dp2[i] = 1e17;
	dp1[s] = dp2[t] = 0;
	cnt1[s] = cnt2[t] = 1;
	
	for(int i = 1; i <= m; i++){
		cin >> u[i] >> v[i] >> w[i];
		gr[u[i]].pb({v[i],w[i]});
		gr[v[i]].pb({u[i],w[i]});
	}
	set < pii > st;
	st.insert({0 , s});
	
	while(sz(st) != 0){
		int u = (*st.begin()).se;
		st.erase(st.begin());
		for(auto to : gr[u]){
			if(dp1[to.fi] == dp1[u] + to.se)
				cnt1[to.fi] += cnt1[u], cnt1[to.fi] %= mod;
			else if(dp1[to.fi] > dp1[u] + to.se){
				st.erase({dp1[to.fi] , to.fi});
				dp1[to.fi] = dp1[u] + to.se;
				cnt1[to.fi] = cnt1[u];
                st.insert({dp1[to.fi],to.fi});
			}
		}
	}    
 
	st.insert({0 , t});
	while(sz(st) != 0){
		int u = (*st.begin()).se;
		st.erase(st.begin());
		for(auto to : gr[u]){
			if(dp2[to.fi] == dp2[u] + to.se)
				cnt2[to.fi] += cnt2[u] , cnt2[to.fi] %= mod;
			else if(dp2[to.fi] > dp2[u] + to.se){
				st.erase({dp2[to.fi] , to.fi});
				dp2[to.fi] = dp2[u] + to.se;
				cnt2[to.fi] = cnt2[u];
                st.insert({dp2[to.fi],to.fi});
			}
		}
	}	
	int tot = cnt1[t] * cnt1[t]%mod;
	for(int i = 1; i <= m; i++){
		if(dp1[u[i]] + dp2[v[i]] > dp2[u[i]] + dp1[v[i]])
			swap(u[i],v[i]);
		if(dp1[u[i]] + dp2[v[i]] + w[i] == dp1[t]){
			int l = max(dp1[u[i]],dp2[v[i]]) , r = min(dp1[u[i]],dp2[v[i]])+w[i];
			if(l < r)
				tot -= cnt1[u[i]] * cnt2[v[i]] % mod * cnt1[u[i]] % mod * cnt2[v[i]] % mod , tot += mod , tot %= mod;//input//
		}
	}
 
	for(int i = 1; i <= n; i++)
		if(dp1[i] + dp2[i] == dp1[t] and dp1[i] == dp2[i])
			tot -= cnt1[i] * cnt2[i] % mod * cnt1[i] %mod * cnt2[i] % mod , tot += mod , tot %= mod;
 
 
	ret(tot);
        
}