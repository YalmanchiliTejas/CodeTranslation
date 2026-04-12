#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
const int MAX_N=100010;
struct Edge{
	int u,v,cost;
	bool operator<(const Edge& rhs) const{
		return cost<rhs.cost;
	}
} ed[MAX_N*4];
vector<int> xs,ys;
int x[MAX_N],y[MAX_N];
PI dicx[MAX_N],dicy[MAX_N];
int N,M;
int par[MAX_N],_rank[MAX_N];
void init(int N){
	for(int i=1;i<=N;i++){
		par[i]=i;
		_rank[i]=0;
	}
}
int find(int x){
	if(par[x]==x) return x;
	return par[x]=find(par[x]);
}
void unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(_rank[x]<_rank[y]){
		par[x]=y;
	}else{
		par[y]=x;
		if(_rank[x]==_rank[y]) _rank[x]++;
	}
}
bool same(int x,int y){
	return find(x)==find(y);
}
void kruskal(){
	sort(ed,ed+M);
	init(N);
	long long ans=0;
	for(int i=0;i<M;i++){
		Edge& e=ed[i];
		if(!same(e.u,e.v)){
			unite(e.u,e.v);
			ans+=e.cost;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		scanf("%d%d",x+i,y+i);
		xs.push_back(x[i]);
		ys.push_back(y[i]);
	}
	memset(dicx,-1,sizeof dicx);
	memset(dicy,-1,sizeof dicy);
	sort(xs.begin(),xs.end());
	sort(ys.begin(),ys.end());
	for(int i=1;i<=N;i++){
		x[i]=lower_bound(xs.begin(),xs.end(),x[i])-xs.begin();
		y[i]=lower_bound(ys.begin(),ys.end(),y[i])-ys.begin();
		if(dicx[x[i]].first==-1)
			dicx[x[i]].first=i;
		else
			dicx[x[i]].second=i;
		if(dicy[y[i]].first==-1)
			dicy[y[i]].first=i;
		else
			dicy[y[i]].second=i;
	}
	for(size_t i=1;i<xs.size();i++){
		if(xs[i]==xs[i-1]) dicx[i]=dicx[i-1];
	}
	for(size_t i=1;i<ys.size();i++){
		if(ys[i]==ys[i-1]) dicy[i]=dicy[i-1];
	}
	for(int i=1;i<=N;i++){
		if(x[i]>0) ed[M++]=(Edge){i,((xs[x[i]-1]==xs[x[i]])?(dicx[x[i]].first==i?dicx[x[i]].second:dicx[x[i]].first):dicx[x[i]-1].first),xs[x[i]]-xs[x[i]-1]};
		if(x[i]+1<(int)xs.size()) ed[M++]=(Edge){i,((xs[x[i]+1]==xs[x[i]])?(dicx[x[i]].first==i?dicx[x[i]].second:dicx[x[i]].first):dicx[x[i]+1].first),xs[x[i]+1]-xs[x[i]]};
		if(y[i]>0) ed[M++]=(Edge){i,((ys[y[i]-1]==ys[y[i]])?(dicy[y[i]].first==i?dicy[y[i]].second:dicy[y[i]].first):dicy[y[i]-1].first),ys[y[i]]-ys[y[i]-1]};
		if(y[i]+1<(int)ys.size()) ed[M++]=(Edge){i,((ys[y[i]+1]==ys[y[i]])?(dicy[y[i]].first==i?dicy[y[i]].second:dicy[y[i]].first):dicy[y[i]+1].first),ys[y[i]+1]-ys[y[i]]};
	}
	kruskal();
	return 0;
}