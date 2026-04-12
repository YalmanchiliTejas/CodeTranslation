#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=(1e18);
const int maxn=(2e5)+10;
int n,m;
ll dp[maxn],sum;
struct node { int x,y; };
vector<node> d[maxn];
ll tr[maxn*4],lazy[maxn*4];
void pushdown(int root) {
	if (!lazy[root]) return;
	tr[root*2]+=lazy[root];
	tr[root*2+1]+=lazy[root];
	lazy[root*2]+=lazy[root];
	lazy[root*2+1]+=lazy[root];
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,ll delta) {
	if (L<=l&&r<=R) {
		tr[root]+=delta;
		lazy[root]+=delta;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,delta);
	if (mid<R) add(L,R,mid+1,r,root*2+1,delta);
	tr[root]=min(tr[root*2],tr[root*2+1]);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	read(m);
	int x,y,z;
	for (int i=1;i<=m;i++) {
		read(x); read(y); read(z);
		d[y].push_back((node){x,z});
		sum+=z;
	}
	for (int i=1;i<=n*4;i++) tr[i]=INF;
	add(0,0,0,n,1,-INF);
	for (int i=1;i<=n+1;i++) {
		for (int j=0;j<d[i-1].size();j++) {
			x=d[i-1][j].x; y=d[i-1][j].y;
			add(0,x-1,0,n,1,y);
		}
		dp[i]=tr[1];
		//printf("%d %lld\n",i,dp[i]);
		if (i>n) break;
		add(i,i,0,n,1,dp[i]-INF);
	}
	printf("%lld\n",sum-dp[n+1]);
	return 0;
}