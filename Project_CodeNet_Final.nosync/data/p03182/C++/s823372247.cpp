#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=2e5+5;
const ll inf=4557430888798830399ll;
vector<pair<int,int> > q[N];
struct tn {
	ll mx,tag;
}t[N*4];

#define lson (Node*2)
#define rson (lson|1)
void pushdown(int Node) {
	if(t[Node].tag==0) return;
	t[lson].tag+=t[Node].tag,t[rson].tag+=t[Node].tag;
	t[lson].mx+=t[Node].tag,t[rson].mx+=t[Node].tag;
	t[Node].tag=0;
}
void modify(int Node,int l,int r,int L,int R,ll v) {
	if(L<=l&&r<=R) {
		t[Node].tag+=v,t[Node].mx+=v;
		return;
	}
	pushdown(Node);
	int mid=(l+r)/2;
	if(L<=mid) modify(lson,l,mid,L,R,v);
	if(mid+1<=R) modify(rson,mid+1,r,L,R,v);
	t[Node].mx=max(t[lson].mx,t[rson].mx);
}
ll query(int Node,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return t[Node].mx;
	pushdown(Node);
	int mid=(l+r)/2; ll ret=-inf;
	if(L<=mid) ret=query(lson,l,mid,L,R);
	if(mid+1<=R) ret=max(ret,query(rson,mid+1,r,L,R));
	return ret;
}

int main() {
	//freopen("1.in","r",stdin);
	//freopen("1.ans","w",stdout);
	
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1,l,r,a;i<=m;++i) {
		scanf("%d%d%d",&l,&r,&a);
		q[r].emplace_back(l,a);
	}
	for(int i=1;i<=n;++i) {
		modify(1,1,n,i,i,query(1,1,n,1,i));
		for(auto x:q[i]) modify(1,1,n,x.first,i,x.second);
		//for(int j=1;j<=n;++j) cerr<<query(1,1,n,j,j)<<' '; cerr<<endl;
	}
	printf("%lld\n",max(t[1].mx,0ll));
	
	return 0;
}
