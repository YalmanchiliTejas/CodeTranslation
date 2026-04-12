#include <bits/stdc++.h>
using namespace std;

#define dump(n) cout<<"# "<<#n<<'='<<(n)<<endl
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define peri(i,a,b) for(int i=int(b);i-->int(a);)
#define rep(i,n) repi(i,0,n)
#define per(i,n) peri(i,0,n)
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

const int INF=1e9;
const int MOD=1e9+7;
const double EPS=1e-9;

template<typename T1,typename T2>
ostream& operator<<(ostream& os,const pair<T1,T2>& p){
	return os<<'('<<p.first<<','<<p.second<<')';
}
template<typename T>
ostream& operator<<(ostream& os,const vector<T>& a){
	os<<'[';
	rep(i,a.size()) os<<(i?" ":"")<<a[i];
	return os<<']';
}

struct Edge{
	int src,dst,cap,flow;
	Edge(){}
	Edge(int s,int d,int c,int f=0):src(s),dst(d),cap(c),flow(f){}
};
struct Graph{
	vector<Edge> es;
	vi head,next;
	Graph(){}
	Graph(int n):head(n,-1){}
	// 有向辺を追加するとき逆辺の容量c2は普通0である．
	// 両方向に容量があるならc2も指定する．
	void AddEdge(int u,int v,int c1,int c2=0){
		es.emplace_back(u,v,c1); next.push_back(head[u]); head[u]=es.size()-1;
		es.emplace_back(v,u,c2); next.push_back(head[v]); head[v]=es.size()-1;
	}
};

void BFS(const Graph& g,int tap,vi& layer)
{
	queue<pii> q; q.emplace(tap,0);
	while(q.size()){
		int u,d; tie(u,d)=q.front(); q.pop();
		if(layer[u]!=INF) continue;
		layer[u]=d;
		for(int i=g.head[u];i!=-1;i=g.next[i])
			if(g.es[i].cap-g.es[i].flow>0)
				q.emplace(g.es[i].dst,d+1);
	}
}

int DFS(Graph& g,int v,int sink,const vi& layer,int flow)
{
	if(v==sink) return flow;
	int f=flow;
	for(int& i=g.head[v];i!=-1;i=g.next[i]){
		Edge& e=g.es[i];
		if(layer[e.src]>=layer[e.dst]) continue;
		int residue=e.cap-e.flow;
		if(residue==0) continue;
		int augment=DFS(g,e.dst,sink,layer,min(residue,f));
		e.flow+=augment;
		g.es[i^1].flow-=augment;
		f-=augment;
		if(f==0) break;
	}
	return flow-f;
}

int Dinic(Graph& g,int tap,int sink)
{
	int res=0;
	for(int n=g.head.size();;){
		vi layer(n,INF);
		BFS(g,tap,layer);
		if(layer[sink]==INF) break;
		vi temp=g.head;
		res+=DFS(g,tap,sink,layer,INF);
		swap(g.head,temp);
	}
	return res;
}

int main()
{
	for(int h,w,c,m,nw,nc,nm;cin>>h>>w>>c>>m>>nw>>nc>>nm && ~h;){
		// 頂点に流量制約があるので二重化する．
		// hero:[0..2h), warrior:[2h,2h+2w),
		// cleric:[2h+2w,2h+2w+2c), mage:[2h+2w+2c,2h+2w+2c+2m)
		int oh=0,ow=2*h,oc=ow+2*w,om=oc+2*c; // offset
		Graph g(2*(h+w+c+m)+8);
		rep(i,w){
			int n; cin>>n;
			rep(_,n){
				int j; cin>>j; j--;
				g.AddEdge(oh+h+j,ow+i,1);
			}
		}
		rep(i,c){
			int n; cin>>n;
			rep(_,n){
				int j; cin>>j; j--;
				g.AddEdge(ow+w+j,oc+i,1);
			}
		}
		rep(i,m){
			int n; cin>>n;
			rep(_,n){
				int j; cin>>j; j--;
				g.AddEdge(oc+c+j,om+i,1);
			}
		}
		
		int xw=2*(h+w+c+m),xc=xw+2,xm=xc+2,tap=xm+2,sink=tap+1;
		rep(i,h) g.AddEdge(oh+i,oh+h+i,1),g.AddEdge(tap,oh+i,1),g.AddEdge(oh+h+i,xw,1);
		rep(i,w) g.AddEdge(ow+i,ow+w+i,1),g.AddEdge(ow+w+i,xc,1);
		rep(i,c) g.AddEdge(oc+i,oc+c+i,1),g.AddEdge(xw+1,oc+i,1),g.AddEdge(oc+c+i,xm,1);
		rep(i,m) g.AddEdge(om+i,om+m+i,1),g.AddEdge(xc+1,om+i,1),g.AddEdge(om+m+i,sink,1);
		g.AddEdge(xw,xw+1,nw);
		g.AddEdge(xc,xc+1,nc);
		g.AddEdge(xm,xm+1,nm);
		g.AddEdge(xm+1,sink,INF);
		
		//for(auto e:g.es) if(e.cap) printf("%d->%d\n",e.src,e.dst);
		
		cout<<Dinic(g,tap,sink)<<endl;
	}
}