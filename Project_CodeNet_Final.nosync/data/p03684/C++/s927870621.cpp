#include <bits/stdc++.h>
#define MOD 1000000007
#define int long long
#define pb push_back
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
int ans=0,n,f[100001],sz[100001],tmp=1; priority_queue<iii,vector<iii>,greater<iii>> edge;
struct point {int x,y,og;} p[100001];
bool cmp(point &a,point &b) {return a.x<b.x;}
bool cmp2(point &a,point &b) {return a.y<b.y;}
int getf(int u) {
	if (u==f[u]) return u;
	else return f[u]=getf(f[u]);
}
void joint(int u,int v) {
	if (sz[u]>sz[v]) {
		f[v]=u;
		sz[u]+=sz[v];
	} else {
		f[u]=v;
		sz[v]+=sz[u];
	}
}
signed main() {
	//freopen("233220.inp","r",stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>n;
	fw (i,0,n) {cin>>p[i].x>>p[i].y; p[i].og=i; f[i]=i;}
	sort(p,p+n,cmp);
	fw (i,0,n-1) edge.push(iii(min(p[i+1].x-p[i].x,abs(p[i+1].y-p[i].y)),ii(p[i].og,p[i+1].og)));
	sort(p,p+n,cmp2);
	fw (i,0,n-1) edge.push(iii(min(p[i+1].y-p[i].y,abs(p[i+1].x-p[i].x)),ii(p[i].og,p[i+1].og)));
	while (!edge.empty()) {
		if (tmp==n) break;
		iii temp=edge.top(); edge.pop(); int cost=temp.first,u=temp.second.first,v=temp.second.second;
		int pu=getf(u),pv=getf(v);
		if (pu!=pv) {
			tmp++;
			ans+=cost;
			joint(pu,pv);
		}
	}
	cout<<ans;
}