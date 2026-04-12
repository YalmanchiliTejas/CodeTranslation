#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lli=long long;
using pii=pair<int,int>;

int n;
pii a[200000];

lli f() {
	int sma=0,smi=1e9,lma=0,lmi=1e9;
	for(int i=0;i<n;i++) {
		if(a[i].fi > a[i].se) swap(a[i].fi,a[i].se);
		sma = max(sma,a[i].fi); smi = min(smi,a[i].fi);
		lma = max(lma,a[i].se); lmi = min(lmi,a[i].se);
	}
	return 1ll*(lma-lmi)*(sma-smi);
}
lli g() {
	int mi=1e9,ma=0,mv=1e9;
	priority_queue<pii,vector<pii>,greater<pii>> que;
	for(int i=0;i<n;i++) {
		if(a[i].fi > a[i].se) swap(a[i].fi,a[i].se);
		que.push(pii(a[i].fi,i+1));
		ma = max(ma,a[i].fi);
	}
	mv = ma - que.top().fi;

	while(!que.empty()) {
		pii cur=que.top();que.pop();
		if(cur.se > 0) {
			cur.se--;
			ma = max(ma, a[cur.se].se);
			que.push(pii(a[cur.se].se, -1));
		} else {
			mi = min(mi, cur.fi);
		}
		mv = min(mv, ma - min(que.top().fi,mi));
	}
	ma=0; mi=1e9;
	for(int i=0;i<n;i++) ma=max(ma,a[i].se),mi=min(mi,a[i].fi);
	return 1ll*(ma-mi)*mv;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d",&a[i].fi,&a[i].se);
	printf("%lld\n",min(f(),g()));
	
	return 0;
}
