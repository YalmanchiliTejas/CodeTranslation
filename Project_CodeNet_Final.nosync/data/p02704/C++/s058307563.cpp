//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}

struct edge
{
	int to,cap,rev;
};
#define SZ 1050
vector<edge>G[SZ];
bool used[SZ];
int itr[SZ],level[SZ];
void init(){
	rep(i, SZ){
		G[i].clear();
		used[i] = 0;
		itr[i] = level[i] = 0;
	}
}
void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}
void bfs(int s){
	memset(level,-1,sizeof(level));
	queue<int>q;
	level[s] = 0; q.push(s);
	while(!q.empty()){
		int v = q.front(); q.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e = G[v][i];
			if(e.cap>0 && level[e.to]<0){
				level[e.to] = level[v]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int t,int f)
{ 
	if(v==t) return f;
	for(int &i=itr[v];i<G[v].size();i++)
	{
		edge &e=G[v][i];
		if(e.cap>0 && level[v] < level[e.to])
		{ 
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0) 
			{ 
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t)
{ 
	int flow=0,f;
	while(bfs(s),level[t]>=0)
	{
		memset(itr,0,sizeof(itr));
		while( (f=dfs(s,t,INF)) > 0){
			flow += f;
		}
	}
	return flow;
}



typedef unsigned long long ull;

int n;
int s[505], t[505];
ull u[505], v[505], ans[505][505];


int main(){
	cin >> n;
	repn(i, n) cin >> s[i];
	repn(i, n) cin >> t[i];
	repn(i, n) cin >> u[i];
	repn(i, n) cin >> v[i];
	rep(b, 64){
		init();
		int ss = 1040, st = 1041;
		int S = 1045, T = 1046;
		repn(i, n){
			repn(j, n){
				add_edge(i, j+n, 1);
			}
		}
		repn(i, n){
			if(s[i] == 0 && ((u[i]>>b)&1ull) == 0){
				add_edge(ss, i, n-1);
			}
			else if(s[i] == 0 && ((u[i]>>b)&1ull) == 1){
				add_edge(S, i, n);
				add_edge(ss, T, n);
				//add_edge(s, i, n, n);
			}
			else if(s[i] == 1 && ((u[i]>>b)&1ull) == 0);
			else{
				add_edge(S, i, 1);
				add_edge(ss, T, 1);
				add_edge(ss, i, n-1);
				//add_edge(s, i, 1, n);
			}
		}
		repn(i, n){
			if(t[i] == 0 && ((v[i]>>b)&1ull) == 0){
				add_edge(i+n, st, n-1);
			}
			else if(t[i] == 0 && ((v[i]>>b)&1ull) == 1){
				add_edge(S, st, n);
				add_edge(i+n, T, n);
				//add_edge(i+n, t, n, n);
			}
			else if(t[i] == 1 && ((v[i]>>b)&1ull) == 0);
			else{
				add_edge(S, st, 1);
				add_edge(i+n, T, 1);
				add_edge(i+n, st, n-1);
				//add_edge(i+n, t, 1, n);
			}
		}
		max_flow(S, T);
		max_flow(ss, T);
		max_flow(S, st);
		max_flow(ss, st);
		repn(i, n){
			rep(j, G[i].size()){
				int x = G[i][j].to;
				x -= n;
				if(1 <= x && x <= n){
					int xx = 1-G[i][j].cap;
					if(xx) ans[i][x] |= (1ull << b);
				}
			}
		}
	}
	repn(i, n){
		ull ts ;
		if(s[i] == 0){
			ts = -1;
			repn(j, n) ts &= ans[i][j];
			//cout << ts << " " << u[i] << endl;
			if(ts != u[i]){
				puts("-1"); return 0;
			}
		}
		else{
			ts = 0;
			repn(j, n) ts |= ans[i][j];
			//cout << ts << " " << u[i] << endl;
			if(ts != u[i]){
				puts("-1"); return 0;
			}
		}
	}
	repn(i, n){
		ull ts = 0;
		if(t[i] == 0){
			ts = -1;
			repn(j, n) ts &= ans[j][i];
			//cout << ts << " " << v[i] << endl;
			if(ts != v[i]){
				puts("-1"); return 0;
			}
		}
		else{
			ts = 0;
			repn(j, n) ts |= ans[j][i];
			//cout << ts << " " << v[i] << endl;
			if(ts != v[i]){
				puts("-1"); return 0;
			}
		}
	}
	repn(i, n){
		repn(j, n) cout << ans[i][j] << " ";
		puts("");
	}
}