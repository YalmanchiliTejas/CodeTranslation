#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<cstring>
#include<queue>
#include<cstdio>
#include<sstream>
#include<iomanip>
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define mp make_pair
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef pair<int,pii> pip;
typedef vector<pip>vip;
const double PI=acos(-1);
const double EPS=1e-8;
const int inf=1e8;
struct edge{int to,cap,rev;};//ikisaki youryou gyakuhen
class MF{//max flow
	public:
	int n;
	vector<vector<edge> >G;//[MAX];
	vector<bool>used;//[MAX];
	MF(int size){
		n=size;
		G=vector<vector<edge> >(n);
	}
	void add_edge(int from, int to, int cap){
		edge q={to,cap,int(G[to].size())};
		G[from].push_back(q);
		q={from,0,int(G[from].size()-1)};
		G[to].push_back(q);
	}
	int dfs(int v,int t, int f) {
		if(v==t)return f;
		used[v]=1;
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(used[e.to]||e.cap<=0) continue;
			int d =dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
		return 0;
	}
	int mf(int s,int t) {//from s to t
		int flow=0,f;
		while(1){
			used=vector<bool>(n,false);
			f=dfs(s,t,inf);
			if(f==0)return flow;
			flow+=f;
		}
	}
};
int main(){
	int H,W,C,M,Nw,Nc,Nm;
	while(cin>>H>>W>>C>>M>>Nw>>Nc>>Nm,H+1){
		MF mf(7+H+W*2+C*2+M);
		int s=H+M+(W+C)*2+5,t=s+1;
		int h=0,w1=H,w2=w1+W+1,c1=w2+W+1,c2=c1+C+1,m=c2+C+1;
		rep(i,H)mf.add_edge(s,i,1);
		rep(i,H)mf.add_edge(i,w1+W,1);
		rep(i,W)mf.add_edge(w1+i,w2+i,1);
		rep(i,C)mf.add_edge(w2+W,c1+i,1);
		rep(i,W)mf.add_edge(w2+i,c1+C,1);
		rep(i,C)mf.add_edge(c1+i,c2+i,1);
		rep(i,M)mf.add_edge(c2+C,m+i,1);
		rep(i,C)mf.add_edge(c2+i,m+M,1);
		rep(i,M)mf.add_edge(m+i,t,1);
		mf.add_edge(w1+W,w2+W,Nw);
		mf.add_edge(c1+C,c2+C,Nc);
		mf.add_edge(m+M,t,Nm);
		rep(i,W){
			int a;
			cin>>a;
			rep(j,a){
				int b;
				cin>>b;b--;
				mf.add_edge(h+b,w1+i,1);
			}
		}
		rep(i,C){
			int a;
			cin>>a;
			rep(j,a){
				int b;
				cin>>b;b--;
				mf.add_edge(w2+b,c1+i,1);
			}
		}
		rep(i,M){
			int a;
			cin>>a;
			rep(j,a){
				int b;
				cin>>b;b--;
				mf.add_edge(c2+b,m+i,1);
			}
		}
		cout<<mf.mf(s,t)<<endl;
	}
}