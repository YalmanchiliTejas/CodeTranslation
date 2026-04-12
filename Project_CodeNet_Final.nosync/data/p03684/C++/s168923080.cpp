#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1061109567
#define int long long
#define pb push_back
#define in(s) freopen(s,"r",stdin);
#define out(s) freopen(s,"w",stdout);
#define fi first
#define se second
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
#define fa(i,x) for (auto i:x)
using namespace std;
const int N=1e5+5;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
struct point {int x,y,id;} p[N];
priority_queue<iii,vector<iii>,greater<iii>> pq;
int n,par[N],sz[N];
bool cmp1(const point &a,const point &b) {return a.x<b.x;}
bool cmp2(const point &a,const point &b) {return a.y<b.y;}
int getp(int u) {return u==par[u]?u:par[u]=getp(par[u]);}
bool joint(int u,int v) {
	u=getp(u),v=getp(v);
	if (u==v) return false;
	if (sz[u]<sz[v]) swap(u,v);
	sz[u]+=sz[v];
	par[v]=u;
	return true;
}
int dist(point x,point y) {
	return min(abs(x.x-y.x),abs(x.y-y.y));
}
signed main() {
	//in("aome.inp");
	//in("PLANTREE.inp"); out("PLANTREE.out");
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//Connect each point to 2 points nearest to it by either x or y. This is all we have to consider
	//for edges. MST easily after.
	cin>>n;
	fw (i,0,n) par[i]=i,sz[i]=1;
	fw (i,0,n) cin>>p[i].x>>p[i].y,p[i].id=i;
	sort(p,p+n,cmp1);
	fw (i,1,n) {
		//pq.push(edge(p[i].id,p[i-1].id,min(p[i].x-p[i-1].x,p[i].y-p[i-1].y)));
		pq.push(iii(dist(p[i],p[i-1]),ii(p[i].id,p[i-1].id)));
	}
	sort(p,p+n,cmp2);
	fw (i,1,n) {
		//pq.push(edge(p[i].id,p[i-1].id,min(p[i].x-p[i-1].x,p[i].y-p[i-1].y)));
		pq.push(iii(dist(p[i],p[i-1]),ii(p[i].id,p[i-1].id)));
	}
	int ans=0;
	while (!pq.empty()) {
		iii foo=pq.top(); pq.pop();
		int u=foo.se.fi,v=foo.se.se,w=foo.fi;
		if (joint(u,v)) {
			ans+=w;
		}
	}
	cout<<ans;
	return 0;
}