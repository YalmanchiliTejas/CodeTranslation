#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r, x)     for (int i = l; i < r; i+=x)
//#define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O 
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << rl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << rl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << rl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << rl;
//#define Ptest(x)            return cout << x, 0;
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calc    
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAX_M = 200010;
// code
#define vi vector<ll>

#define ii pair<int,int>
#define iii pair<int,ii>
#define _path pair<ll,pair<ll,int> > // length, numlength, node,we also take numlength to be negetive so that paths with the same length is sorted by descending order of number of such path. this is eSential otherwise it wpair<int, int>l lead to undercounting of number of same length paths
//#define endl '\n'
 
vector<pair<int, int>> g[MAXN];
int n;
int S;
int T;
 
ll dist[2][MAXN];
ll cnt[2][MAXN];
bool vis[MAXN];
 
void dijk(int s){
	priority_queue<_path, vector<_path>, greater<_path> > pq;
	pq.push({0,{-1,s}});
	
	bool x = s == S;
	for(int i = 0; i < n; i++){
	    dist[x][i] = 1e18;
	    vis[i] = 0;
	}
	dist[x][s] = 0;
	cnt[x][s] = 1;
	
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop();
		if(dist[x][cur.S.S] < cur.F)
		    continue;
		if(vis[cur.S.S])
		    continue;
		vis[cur.S.S] = 1;
 
		for(auto e: g[cur.S.S]){
			if(dist[x][e.F] < cur.F + e.S)
			    continue;
			if(dist[x][e.F] == cur.F + e.S){
				cnt[x][e.F] += cnt[x][cur.S.S];
				cnt[x][e.F] %= mod;
			}else{
				dist[x][e.F] = cur.F + e.S;
				cnt[x][e.F] = cnt[x][cur.S.S];
				pq.push(make_pair(dist[x][e.F],make_pair(cnt[x][cur.S.S],e.F)));				
			}
		}
	}
}

void Solve() {
	int m;
	cin >> n >> m >> S >> T;
	S--; T--;
	vector<pair<pii, ll>> allEdges;
	for(int i = 0; i < m; i++){
		int a,b; ll c;
		cin >> a >> b >> c;
		g[a-1].pb({b-1, c});
		g[b-1].pb({a-1, c});
		allEdges.pb({{a-1, b-1}, c});
	}
	
	dijk(S); dijk(T);
 
	ll way = cnt[1][T];
	ll ans = (way*way)%mod;
	
	for(int i = 0; i < n; i++){
		if(dist[0][i] + dist[1][i] == dist[1][T] and dist[0][i] == dist[1][i]){
			ll xx =(cnt[0][i] * cnt[1][i]) % mod; 
			ans -= (xx * xx) % mod;
			ans %= mod;
		}
	}
	
	for(auto e: allEdges){
		if(min(dist[0][e.F.F], dist[0][e.F.S]) + min(dist[1][e.F.F], dist[1][e.F.S]) + e.S != dist[0][S])
			continue;
		
		if(dist[0][e.F.F] > dist[0][e.F.S]) swap(e.F.F,e.F.S);
		pll vis1 = {dist[0][e.F.F], dist[0][e.F.S]};
		pll vis2 = {dist[1][e.F.S], dist[1][e.F.F]};
		
		//cout << vis1.F << " " << vis1.S << " " << vis2.F << " " << vis2.S << endl;
		
		if(!(vis1.S <= vis2.F || vis1.F >= vis2.S)){
			ll xx = (cnt[0][e.F.F] * cnt[1][e.F.S]) % mod;
			ans -= (xx * xx)%mod;
			ans %= mod;
		}
	}

	ans %= mod;
	ans += mod;
	ans %= mod;
	
	cout << ans << endl;
}

signed main(){
    FAST_IO;
    int TC = 1; 
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}
