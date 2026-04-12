//By Ralif Rakhmatullin
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<queue>
#include<stack>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<bitset>
#include<valarray>
#include<iterator>
#include<list>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define S second
#define ld long double
#define F first
#define y1 LOL
#define ld long double
#define pb push_back
#define len length
#define sz size
#define beg begin
const ll INF = (ll)1e18 + 123;
const int inf=(int)2e9 + 123; 
const int mod=1e9+7;
using namespace std;
int n, m;
vector<pair<int, ll> > g[200011];
ll d1[200011], d2[200011], dp1[200011], dp2[200011];
int s, t; 
struct edge{
	int fr, to;
	ll c;
	edge(){
		fr = 0;
		to = 0;
		c = 0;
	}
	edge(int x, int y, ll z){
		fr = x;
		to = y;
		c = z;
	}
};
ll add(ll x, ll y){
	return (x + y) % mod;
}
ll sub(ll x, ll y){
	return (x - y + mod) % mod;
}
vector<edge> e;
int main(){
	unsigned int FOR;
 	asm("rdtsc" : "=A"(FOR));
  	srand(FOR);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin >> n >> m >> s >> t;
	for(int i = 1; i <= m; i ++){
		int x, y;
		ll c;
		cin >> x >> y >> c;
		g[y].pb(mp(x, c));
		g[x].pb(mp(y, c));
		e.pb(edge(x, y, c));
	//	e.pb(edge(y, x, c));
	}
	for(int i = 1; i <= n; i ++){
		d1[i] = d2[i] = INF;
	}               
	d1[s] = 0;
	d2[t] = 0;
	dp1[s] = 1;
	dp2[t] = 1;
	priority_queue<pair<ll, int> > q;
	q.push(mp(0, s));
	while(q.sz()){
		int v = q.top().S;
		ll cost = -q.top().F;
		q.pop();
		if(cost > d1[v])
			continue;
	   	for(auto to : g[v]){
	   		if(d1[to.F] > d1[v] + to.S){
	   			d1[to.F] = d1[v] + to.S;
	   			dp1[to.F] = dp1[v];
	   			q.push(mp(-d1[to.F], to.F));
	   		}else
	   		if(d1[to.F] == d1[v] + to.S)
	   			dp1[to.F] = add(dp1[to.F], dp1[v]);
	   	}
	}
	q.push(mp(0, t));
	while(q.sz()){
		int v = q.top().S;
		ll cost = -q.top().F;
		q.pop();
		if(cost > d2[v])
			continue;
	   	for(auto to : g[v]){
	   		if(d2[to.F] > d2[v] + to.S){
	   			d2[to.F] = d2[v] + to.S;
	   			dp2[to.F] = dp2[v];
	   			q.push(mp(-d2[to.F], to.F));
	   		}else
	   		if(d2[to.F] == d2[v] + to.S)
	   			dp2[to.F] = add(dp2[to.F], dp2[v]);
	   	}
	}                     	
	ll ans = 1ll * dp1[t] * dp1[t];
	ans %= mod;    
	for(int i = 1; i <= n; i ++){
	   	if(d1[i] == d2[i] && d1[i] + d2[i] == d1[t]){
	   		ans = sub(ans, (((1ll * dp1[i] * dp2[i]) % mod) * ((1ll * dp1[i] * dp2[i]) % mod)) % mod);
	   	}
	}                                                                    
	for(int i = 0; i < e.sz(); i ++){
		int x = e[i].fr, y = e[i].to;
		ll c = e[i].c;
		if(d1[x] > d1[y])
			swap(x, y);
		if(d1[x] + d2[y] + c == d1[t] && ((d1[x] <= d2[y] && d1[x] + c > d2[y]) || (d1[x] > d2[y] && d2[y] + c > d1[x]))){
			ans = sub(ans, (((1ll * dp1[x] * dp1[x]) % mod) * ((1ll * dp2[y] * dp2[y]) % mod)) % mod);
		}
	}                                                                      
	cout << ans << endl;
	return 0;
}
//     ((d1[x] < d2[y] && d1[x] + c > d2[y]) || (d1[x] > d2[y] && d2[y] + c > d1[x]))