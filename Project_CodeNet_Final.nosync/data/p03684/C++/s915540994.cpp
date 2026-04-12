#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF=1e9+7;
const LL N=100001;
priority_queue<pair<LL,pair<LL,LL> > > Q;
LL n,par[N],a,ans=0;
void init(int n){
	for(LL i=1;i<n+1;i++) par[i]=i;
}
int root(int x){
	if(par[x]==x) return x;
	else return par[x]=root(par[x]);
}
void unite(int x,int y){
	x=root(x);
	y=root(y);
	if(x==y) return;
	par[x]=y;
}
pair<LL,LL> x[N],y[N];
int main(){
	cin>>n;
	init(n);
	for(LL i=0;i<n;i++){
		cin>>x[i].first>>y[i].first;
		x[i].second=i;
		y[i].second=i;
	}
	sort(x,x+n);
	sort(y,y+n);
	for(LL i=0;i<n-1;i++){
		Q.push(make_pair(-(abs(x[i].first-x[i+1].first)),make_pair(x[i].second,x[i+1].second)));
		Q.push(make_pair(-(abs(y[i].first-y[i+1].first)),make_pair(y[i].second,y[i+1].second)));
	}
	while(!Q.empty()){
		pair<LL,LL> e;
		LL cost,xx,yy;
		pair<LL,pair<LL,LL> > q;
		q=Q.top();
		e=q.second;
		cost=-q.first;
		xx=e.first;
		yy=e.second;
		Q.pop();
		if(root(xx)==root(yy))continue;
		unite(xx,yy);
		ans+=cost;
	}
	cout<<ans<<endl;
	return 0;
}