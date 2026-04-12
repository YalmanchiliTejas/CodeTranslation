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

struct flowGraph{
	struct edge{ int to, cap, rev; };
	
	int n, *level, *iter;
	vector<vector<edge> > G;
	
	flowGraph(int sz) : n(sz){
		G.resize(n);
		iter = new int[n]; level = new int[n];
	}
	~flowGraph(){
		delete [] iter; delete [] level;
	}
	
	void add(int s, int t, int cap){
		G[s].pb((edge){t, cap, (int)G[t].size()});
		G[t].pb((edge){s, 0, (int)G[s].size() - 1});
	}
	void bfs(int s){
		rep(i, n) level[i] = -1;
		queue<int> q;
		level[s] = 0;
		q.push(s);
		while(!q.empty()){	
			int v = q.front();
			q.pop();
			rep(i, G[v].size()){
				edge &e = G[v][i];
				if(e.cap > 0 && level[e.to] < 0){
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}
	int dfs(int v, int t, int f){
		if(v == t) return f;
		for(int &i = iter[v]; i < (int)G[v].size(); i++){
			edge &e = G[v][i];
			if(e.cap > 0 && level[v] < level[e.to]){
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t){
		int flow = 0;
		while(1){
			bfs(s);
			if(level[t] < 0) return flow;
			rep(i, n) iter[i] = 0;
			int f;
			while((f = dfs(s, t, inf)) > 0) flow += f;
		}
	}
};

bool can(int n, const vector<pi> &es, int low, int diff){
	int m = es.size();
	int s = n + m, t = s + 1;
	int S = t + 1, T = S + 1;
	
	auto check = [&](bool pre_check){
		flowGraph g(T + 1);
		int id = 0;
		for(auto p : es){
			int a = p.first, b = p.second;
			g.add(s, id, 1);
			g.add(id, a + m, 1);
			g.add(id, b + m, 1);
			id++;
		}
		rep(i, n){
			g.add(i + m, t, diff);
			g.add(S, t, low);
			g.add(i + m, T, low);
		}
		if(pre_check){
			g.add(t, s, inf);
		}
		else{
			g.add(S, s, inf);
			g.add(t, T, inf);
		}
		return g.max_flow(S, T);
	};
	if(check(1) < n * low) return 0;
	if(check(0) - n * low < m) return 0;
	return 1;
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n, m;
	while(cin >> n >> m, n){
		vector<pi> es;
		rep(i, m){
			int a, b; cin >> a >> b; a--; b--;
			es.emplace_back(a, b);
		}
		int ans = n, ansl;
		for(int low = m / n; low >= 0 && ans > 0; low--){
			/*
			if(!can(n, es, low, ans - 1)) continue;
			ans--;
			while(ans > 0 && can(n, es, low, ans - 1)) ans--;
			ansl = low;
			*/
			if(!can(n, es, low, ans)) continue;
			int lo = -1, hi = ans, mid;
			while(lo + 1 < hi){
				mid = (lo + hi) / 2;
				if(can(n, es, low, mid)) hi = mid;
				else lo = mid;
			}
			//dbg(low, lo, hi);
			if(ans == hi) continue;
			ans = hi;
			ansl = low;
		}
		cout << ansl << " " << ansl + ans << endl;
	}
	return 0;
}