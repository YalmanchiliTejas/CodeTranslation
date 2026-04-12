#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define pq priority_queue
#define mp make_pair
#define pii pair<int,int>
#define mod 998244353

int lowbit(int x) {return x&(-x);}

int n,m;
vector <pii> p[200010];
long long tree[800040];
long long tag[800040];

void update(int cur,int l,int r,int ll,int rr,long long c) {
	if (ll<=l&&rr>=r) {
		tree[cur]+=c;
		tag[cur]+=c;
		return; 
	}
	int mid=(l+r)>>1;
	if (ll<=mid) update(cur*2,l,mid,ll,rr,c);
	if (rr>mid) update(cur*2+1,mid+1,r,ll,rr,c);
	tree[cur]=max(tree[cur*2],tree[cur*2+1])+tag[cur];
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++) {
		int l,r,a;
		scanf("%d%d%d",&l,&r,&a);
		p[r].pb(mp(l,a));
	}
	for (int i=1;i<=n;i++) {
		update(1,1,n,i,i,tree[1]);
		for (int j=0;j<p[i].size();j++)
			update(1,1,n,p[i][j].fi,i,p[i][j].se);
	}
	cout<<max(0ll,tree[1]);
	return 0;
}
