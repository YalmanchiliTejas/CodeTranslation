#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;
const int mod = 1e9 + 7;
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	int n, m, s, t;
	cin >> n >> m >> s >> t; s--; t--;
	vector<vector<pi>> e(n);
	rep(i, m){
		int a, b, c; cin >> a >> b >> c; a--; b--;
		e[a].emplace_back(b, c);
		e[b].emplace_back(a, c);
	}
	vi way1(n), way2(n);
	
	auto dij = [&](int s, int t, vi &way, vector<ll> &dist){
		vi vis(n);
		way[s] = 1;
		dist[s] = 0;
		
		priority_queue<pair<ll, int>> q;
		q.emplace(0, s);
		while(!q.empty()){
			ll co = -q.top().first;
			int c = q.top().second; q.pop();
			if(vis[c]) continue;
			vis[c] = 1;
			
			for(pi i : e[c]) if(dist[i.first] >= co + i.second){
				
				if(dist[i.first] > co + i.second){
					dist[i.first] = co + i.second;
					way[i.first] = 0;
					q.emplace(-co - i.second, i.first);
				}
				(way[i.first] += way[c]) %= mod;
			}
		}
	};
	
	vector<ll> dist1(n, 1e18), dist2(n, 1e18);
	dij(s, t, way1, dist1);
	dij(t, s, way2, dist2);
	ll ans = (ll)way1[t] * way2[s] % mod;
	
	assert(way1[t] == way2[s]);
	assert(dist1[t] == dist2[s]);
	/*
	rep(i, n) dbg(i, dist1[i]);
	rep(i, n) dbg(i, way1[i]);
	
	rep(i, n) dbg(i, dist2[i]);
	rep(i, n) dbg(i, way2[i]);
	
	dbg(ans);
	*/
	rep(i, n) if(dist1[i] * 2 == dist1[t] && dist2[i] * 2 == dist2[s]){
		ll x = (ll)way1[i] * way2[i] % mod;
		ans += mod - x * x % mod;
		ans %= mod;
	}
	rep(i, n) if(2 * dist1[i] < dist1[t]) for(pi p : e[i]) if(2 * dist1[p.first] > dist1[t]){
		if(dist1[i] + p.second + dist2[p.first] != dist1[t]) continue;
		//if(dist1[p.first] != dist1[i] + p.second || dist2[i] != dist2[p.first] + p.second) continue;
		if(!(2 * dist2[i] > dist2[s] && 2 * dist2[p.first] < dist2[s])) continue;
		
		ll x = (ll)way1[i] * way2[p.first] % mod;
		ans += mod - x * x % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}