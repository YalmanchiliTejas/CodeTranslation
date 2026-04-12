#include <bits/stdc++.h>
using namespace std;
#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define in(x,y,h,w) x >= 0 && x < h && y >= 0 && y < w

#define int long long
//typedef    long long          ll;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      P;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
 
const int INF=1e+18;
const double EPS=1e-9;
const int MOD=1000000007;
 
const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

struct edge{ int to,cost; };

int n,m,s,t,d[100000];
vector<edge> G[100000];
vector<P> vec;

void dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> > que;
	for(int i = 0;i < n;i++) d[i] = INF;
	d[s] = 0;
	que.push(P(0,s));
	while(!que.empty()){
		P p = que.top();
		que.pop();
		int v = p.second;
		if(d[v] < p.first) continue;
		for(int i = 0;i < G[v].size();i++){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}
}

signed main(){
	int nums[100000] = {},numt[100000] = {},ans;
	cin >> n >> m >> s >> t; s--;t--;
	for(int i = 0;i < m;i++){
		int a,b,c;
		cin >> a >> b >> c; a--;b--;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
	}
	dijkstra(s);
	for(int i = 0;i < n;i++) vec.push_back(P(d[i],i));
	sort(all(vec));
	nums[s] = 1;
	numt[t] = 1;
	for(int i = 0;i < n;i++){
		int v = vec[i].second;
		for(edge e : G[v]){
			if(d[e.to] == d[v] + e.cost) nums[e.to] = (nums[e.to] + nums[v]) % MOD;
		}
	}
	for(int i = n - 1;i >= 0;i--){
		int v = vec[i].second;
		for(edge e : G[v]){
			if(d[e.to] == d[v] - e.cost) numt[e.to] = (numt[e.to] + numt[v]) % MOD;
		}
	}
	ans = nums[t] * nums[t];
	for(int i = 0;i < n;i++){
		if(d[i] * 2 == d[t]) ans = (ans - nums[i] * nums[i] % MOD * numt[i] % MOD * numt[i] % MOD + MOD) % MOD;
		for(edge e : G[i]){
			if(d[i] + e.cost == d[e.to] && d[i] * 2 < d[t] && d[t] < d[e.to] * 2) ans = (ans - nums[i] * nums[i] % MOD * numt[e.to] % MOD * numt[e.to] % MOD + MOD) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}