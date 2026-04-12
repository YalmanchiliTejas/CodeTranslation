#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

struct edge{
	int u,v,id;
	ll w;
	edge(){}
	edge(int uu,int vv,ll ww,int ii){
		u=uu;
		v=vv;
		w=ww;
		id=ii;
	}
	bool operator<(const edge &e)const{
		return w<e.w;
	}
};

struct edge2{
	int v,id;
	ll w;
	edge2(){}
	edge2(int vv,ll ww,int ii){
		v=vv;
		w=ww;
		id=ii;
	}
};

struct uftree{
	static const int N=100005;
	int par[N];
	int rank[N];

	void init(){
		for(int i=0;i<N;i++){
			par[i]=i;
		}
	}
	int find(int x){
		if(par[x]==x)return x;
		return par[x]=find(par[x]);
	}
	void unite(int a,int b){
		a=find(a);
		b=find(b);
		if(a==b)return;
		if(rank[a]<rank[b]){
			par[a]=b;
		}else{
			if(rank[a]==rank[b])rank[a]++;
			par[b]=a;
		}
	}

	bool same(int a,int b){
		return (find(a)==find(b));
	}
};

struct lcatree{
	static const int MAX_LOG=20;
	static const int MAX=400005;
	vector<int> G[MAX];
	int root;
	int parent[MAX_LOG][MAX];
	int depth[MAX];
	void dfs(int v,int p,int d){
		parent[0][v]=p;
		depth[v]=d;
		for(int i=0;i<G[v].size();i++){
			if(G[v][i]!=p)dfs(G[v][i],v,d+1);
		}
	}
	void init(int V){
		dfs(root,-1,0);
		for(int k=0;k+1<MAX_LOG;k++){
			for(int v=0;v<V;v++){
				if(parent[k][v]<0)parent[k+1][v]=-1;
				else parent[k+1][v]=parent[k][parent[k][v]];
			}
		}
	}
	int lca(int u,int v){
		if(depth[u]>depth[v])swap(u,v);
		for(int k=0;k<MAX_LOG;k++){
			if((depth[v]-depth[u])>>k & 1){
				v=parent[k][v];
			}
		}
		if(u==v)return u;
		for(int k=MAX_LOG-1;k>=0;k--){
			if(parent[k][u]!=parent[k][v]){
				u=parent[k][u];
				v=parent[k][v];
			}
		}
		return parent[0][u];
	}
};

class RMHeap{
public:
	unsigned long long seed=1145141919LL;
	int next(){
		seed=seed^(seed<<13);
		seed=seed^(seed>>7);
		seed=seed^(seed<<17);
		return (seed>>33);
	}
	static const int MAX=514514;
	int N=1;
	P key[MAX];
	int ch[2][MAX];

	void init(){
		for(int i=0;i<MAX;i++){
			key[i]=P(-1,-1);
		}
	}

	int merge(int i,int j){
		if(i==0 || j==0)return (i!=0)?i:j;
		if(key[i]>key[j])swap(i,j);
		int b=rand()%2;
		ch[b][i]=merge(ch[b][i],j);
		return i;
	}

	int newnode(P k){
		key[N]=k;
		ch[0][N]=ch[1][N]=0;
		return N++;
	}

	int push(int i,P k){
		return merge(i,newnode(k));
	}
	int pop(int i){
		return merge(ch[0][i],ch[1][i]);
	}
	P top(int i){
		return key[i];
	}
};

int n,m;
edge e[200005];
vector<edge2> G[100005],notG[100005];
uftree uf;
lcatree lc;
RMHeap heap;
bool used[200005];
ll ans[200005];
int par[100005];

void dfs(int v,int p,int id,ll pw){
	for(int i=0;i<G[v].size();i++){
		if(G[v][i].v!=p){
			dfs(G[v][i].v,v,G[v][i].id,G[v][i].w);
			par[v]=heap.merge(par[v],par[G[v][i].v]);
		}
	}
	for(int i=0;i<notG[v].size();i++){
		par[v]=heap.push(par[v],P(notG[v][i].w,notG[v][i].v));
	}
	if(id!=-1){
		ans[id]-=pw;
		while(1){
			P p=heap.top(par[v]);
			if(p.first==-1){
				ans[id]=-1;
				break;
			}else if(lc.lca(p.second,v)!=v){
				ans[id]+=p.first;
				break;
			}
			par[v]=heap.pop(par[v]);
		}
	}
}

void solve(ll cost){
	lc.init(n);
	heap.init();
	for(int i=0;i<m;i++){
		ans[i]=cost;
	}
	dfs(0,-1,-1,-1);
	for(int i=0;i<m;i++){
		printf("%lld\n",ans[i]);
	}
}

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		scanf("%d%d%lld",&a,&b,&c);
		a--;
		b--;
		e[i]=edge(a,b,c,i);
	}
	sort(e,e+m);
	int cnt=0;
	ll su=0;
	uf.init();
	for(int i=0;i<m;i++){
		if(!uf.same(e[i].u,e[i].v)){
			su+=e[i].w;
			cnt++;
			used[e[i].id]=true;
			uf.unite(e[i].u,e[i].v);
			lc.G[e[i].u].push_back(e[i].v);
			lc.G[e[i].v].push_back(e[i].u);
			G[e[i].u].push_back(edge2(e[i].v,e[i].w,e[i].id));
			G[e[i].v].push_back(edge2(e[i].u,e[i].w,e[i].id));
		}else{
			notG[e[i].u].push_back(edge2(e[i].v,e[i].w,e[i].id));
			notG[e[i].v].push_back(edge2(e[i].u,e[i].w,e[i].id));
		}
	}
	if(cnt!=(n-1)){
		for(int i=0;i<m;i++){
			printf("-1\n");
		}
	}else{
		solve(su);
	}
	return 0;
}
