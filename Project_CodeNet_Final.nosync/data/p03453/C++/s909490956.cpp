#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-10;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

class Graph{
	private:
	int n;
	vvp g;
	vl DIJ(int s){
		priority_queue<pll> q;
		vl d(n,INF);
		d[s]=0;
		q.push({0,s});
		while(!q.empty()){
			pll p=q.top();
			q.pop();
			int v=p.second;
			if(d[v]<-p.first) continue;
			for(int i=0;i<g[v].size();i++){
				ll F=g[v][i].first,S=g[v][i].second;
				if(d[F]>d[v]+S){
					d[F]=d[v]+S;
					q.push({-d[F],F});
				}
			}
		}
		return d;
	}
	public:
	Graph(int v){
		n=v;
		g=vvp(v);
	}
	void add_edge(int s,int t,int c){
		g[s].push_back({t,c});
		g[t].push_back({s,c});
	}
	vl f(int v,ll D){
		vl d=DIJ(v),dp(n);
		dp[v]++;
		vpll a(n);
		for(int i=0;i<n;i++) a[i]={d[i],i};
		sort(a.begin(),a.end());
		for(int i=0;i<n;i++){
			int v=a[i].second;
			for(int j=0;j<g[v].size();j++){
				int u=g[v][j].first,c=g[v][j].second;
				if(d[v]==d[u]+c) (dp[v]+=dp[u])%=mod;
			}
		}
		for(int i=0;i<n;i++) dp[i]=dp[i]*dp[i]%mod;
		return dp;
	}
	ll solve(int s,int t){
		vl d=DIJ(s),d_=DIJ(t);
		ll D=d[t];
		vl a=f(s,D),b=f(t,D);
		ll res=0,sum=a[t];
		double D2=(double)D/2;
		for(int i=0;i<n;i++) if(D%2==0&&D/2==d[i]) (res+=a[i]*b[i])%=mod;
		for(int v=0;v<n;v++) for(int j=0;j<g[v].size();j++){
			int u=g[v][j].first,c=g[v][j].second;
			if((double)d[v]<D2&&D2<(double)d[u]&&d[v]+d_[u]+c==D){
				(res+=a[v]*b[u])%=mod;
			}
		}
		res=(sum-res+mod)%mod;
		return res;
	}
};

int n,m,u,v;

int main(){
	cin>>n>>m>>u>>v;
	Graph g(n);
	for(int i=0;i<m;i++){
		int s,t,c;
		cin>>s>>t>>c;
		g.add_edge(s-1,t-1,c);
	}
	cout<<g.solve(u-1,v-1)<<endl;
}