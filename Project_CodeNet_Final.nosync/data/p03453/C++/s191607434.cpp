#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
#define ws GON
#define MOD 1000000007

int n,m,s,t;
vector<pair<int,ll> > g[100005];
ll ds[100005],dt[100005],qs[100005],qt[100005];
priority_queue<pair<ll,int> > q;

void dijkstra(int x, ll *d, ll *qq){
	fore(i,0,n)d[i]=1LL<<61;
	d[x]=0;q.push(mp(0LL,x));
	qq[x]=1;
	while(!q.empty()){
		auto p=q.top();q.pop();
		int x=p.snd;ll dd=-p.fst;
		if(d[x]!=dd)continue;
		for(auto p:g[x]){
			int y=p.fst;ll c=p.snd;
			if(d[x]+c<d[y]){
				d[y]=d[x]+c;
				q.push(mp(-d[y],y));
				qq[y]=qq[x];
			}
			else if(d[x]+c==d[y])qq[y]+=qq[x],qq[y]%=MOD;
		}
	}
}

set<pair<pair<int,int>,ll> > ws,wt;

void doit(ll *d0, ll *d1, ll *q0, ll *q1, set<pair<pair<int,int>,ll> >& w, ll a){
	//printf(" %lld\n",a);
	fore(i,0,n)if(d0[i]==a&&d1[i]==a)w.insert(mp(mp(i,-1),q0[i]*q1[i]%MOD));
	fore(x,0,n)for(auto p:g[x]){
		int y=p.fst;ll c=p.snd;
		//if(d0[x]+d1[x]==2*a&&d0[y]+d1[y]==2*a)
		//if(d0[x]<a&&d0[y]>a&&d0[y]==d0[x]+c)
		if(d0[x]+c+d1[y]==2*a&&d0[x]+c>a&&d1[y]+c>a)
			w.insert(mp(mp(min(x,y),max(x,y)),q0[x]*q1[y]%MOD));
	}
}

int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);s--;t--;
	fore(_,0,m){
		int x,y;ll d;
		scanf("%d%d%lld",&x,&y,&d);d*=2;x--;y--;
		g[x].pb(mp(y,d));
		g[y].pb(mp(x,d));
	}
	dijkstra(s,ds,qs);
	dijkstra(t,dt,qt);
	doit(ds,dt,qs,qt,ws,ds[t]/2);
	//doit(dt,wt,dt[s]/2);
	ll r=0,s=0;

	for(auto p:ws)s+=p.snd,s%=MOD;
	for(auto p:ws){
		ll a=(s-p.snd+MOD)%MOD;
		r+=p.snd*a%MOD;
		r%=MOD;
	}


	printf("%lld\n",r);
	return 0;
}