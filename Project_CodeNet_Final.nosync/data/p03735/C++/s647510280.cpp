#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000100
#define M 1000000007ll
#define INFLL 1000000000000000010ll
#define UQ(x) (x).resize(distance((x).begin(),unique(all((x)))))
#define mid(x,y) (((x)+(y))>>1)

int n,x[200005],y[200005];
vector<ii> o2,o;
vector<int> h,l;
int pr[200005];
int main() {
	scanf("%d",&n);
	int vmin=INF,vmax=-1;
	for (int i=0;i<n;i++) {
		scanf("%d%d",&x[i],&y[i]);
		if (x[i]>y[i]) swap(x[i],y[i]);
		vmax=max(vmax,y[i]);
		vmin=min(vmin,x[i]);
	}
	int rmin=vmax;
	int bmax=vmin;
	for (int i=0;i<n;i++) {
		rmin=min(rmin,y[i]);
		bmax=max(bmax,x[i]);
	}
	ll ans=(ll)(vmax-rmin)*(ll)(bmax-vmin);

	for (int i=0;i<n;i++) {
		if (x[i]==vmin && y[i]==vmax) {
			//special
			printf("%lld\n", ans);
			return 0;
		}
		if (x[i]==vmin) {
			l.pb(y[i]);
		} else if (y[i]==vmax) {
			h.pb(x[i]);
		} else {
			o2.pb(mp(x[i],y[i]));
		}
	}
	sort(all(l));
	sort(all(h));
	sort(all(o));
	UQ(o);

	int bmin=min(h[0],l[0]);
	bmax=max(h.back(),l.back());

	for (ii p:o2) {
		bmax=max(bmax,p.first);
		bmin=min(bmin,p.second);
	}

	for (ii p:o2) {
		if (p.first<bmin && p.second>bmax) {
			o.pb(p);
		}
	}
	int cl=bmax-bmin;
	if (!o.empty()) {
		int cur=bmax-o[0].first;
		sort(all(o));
		pr[0]=o[0].second;
		for (int i=1;i<sz(o);i++) {
			pr[i]=max(pr[i-1],o[i].second);
		}
		for (int i=1;i<sz(o);i++) {
			cur=min(cur,max(bmax,pr[i-1])-o[i].first);
		}
		cl=cur;
	}
	ans=min(ans,(ll)cl*(ll)(vmax-vmin));
	printf("%lld\n", ans);
}