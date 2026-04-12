#include<bits/stdc++.h>
#pragma O3
using namespace std;
struct node{
	int v,l,r;
};
struct no{
	int x,y,p;
};
struct cmp1{
	bool operator()(no a,no b){
		if(a.x!=b.x) return a.x<b.x;
		if(a.y!=b.y) return a.y<b.y;
		return a.p<b.p;
	}
};
struct cmp2{
	bool operator()(no a,no b){
		if(a.y!=b.y)return a.y<b.y;
		if(a.x!=b.x) return a.x<b.x;
		return a.p<b.p;
	}
};
struct cmppq{
	bool operator()(node a,node b){
		if(a.v!=b.v) return a.v>b.v;
		if(a.l!=b.l) return a.l>b.l;
		return a.r>b.r;
	}
};
vector<no> r;
priority_queue<node,vector<node>,cmppq> pq;
int par[100004];
int Find(int x){
	if(x!=par[x]) par[x]=Find(par[x]);
	return par[x];
}
void Union(int x,int y){
	int px=Find(x);
	int py=Find(y);
	if(px!=py) par[py]=px;
}
signed main(){
//	freopen(".inp","r",stdin);
//	freopen(".out","w",stdout);
//	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,u,v,tmp,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>u>>v;
		r.push_back({u,v,i});
		par[i]=i;
	}
	sort(r.begin(),r.end(),cmp1());
	for(int i=0;i<n-1;i++){
		tmp=min(abs(r[i].x-r[i+1].x),abs(r[i].y-r[i+1].y));
		pq.push({tmp,r[i].p,r[i+1].p});
	}
	sort(r.begin(),r.end(),cmp2());
	for(int i=0;i<n-1;i++){
		tmp=min(abs(r[i].x-r[i+1].x),abs(r[i].y-r[i+1].y));
		pq.push({tmp,r[i].p,r[i+1].p});
	}
	while(!pq.empty()){
		u=pq.top().l;
		v=pq.top().r;
		if(Find(u)!=Find(v)){
			ans+=pq.top().v;
			Union(u,v);
		}
		pq.pop();
	}
	cout<<ans;
}
