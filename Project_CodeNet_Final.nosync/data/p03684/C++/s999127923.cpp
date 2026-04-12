#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(ll I = (A); I < (B); ++I)
const ll INF=1e9+7;
const ll N = 100001;
ll n;
priority_queue <pair< ll , pair<ll,ll> > > Q;

ll par[N];
ll a,ans=0;

void init(int n){
	FOR(i,1,n+1)par[i]=i;
}

int root(int x){
	if(par[x]==x){
		return x;
	}else{
		return par[x] = root(par[x]);
	}
}

void unite(int x,int y){
	x=root(x);
	y=root(y);
	if(x==y)return;
	par[x]=y;
}
pair<ll,ll> x[N],y[N];


int main(){
	cin>>n;
	init(n);
	FOR(i,0,n){
		cin>>x[i].first>>y[i].first;
		x[i].second=i;
		y[i].second=i;
	}
	sort(x,x+n);
	sort(y,y+n);
	FOR(i,0,n-1){
		Q.push(make_pair(-(abs(x[i].first-x[i+1].first)),make_pair(x[i].second,x[i+1].second)));
		Q.push(make_pair(-(abs(y[i].first-y[i+1].first)),make_pair(y[i].second,y[i+1].second)));
	}
	while(!Q.empty()){
		pair<ll,ll> e;
		ll cost,xx,yy;
		pair<ll,pair<ll,ll> > q;
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