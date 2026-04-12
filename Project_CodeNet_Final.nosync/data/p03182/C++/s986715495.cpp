#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define mid ((l + r) >> 1)
#define lson (x << 1)
#define rson ((x << 1) | 1)
using namespace std;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

struct node{
	LL l,r,v;
}s[200005];
bool cmp(node x,node y){ return x.r < y.r; }

LL tag[800005] = {0};
LL val[800005] = {0};

void pushdown(LL x,LL l,LL r){
	if(!tag[x]) return;
	tag[lson] += tag[x]; val[lson] += tag[x];
	tag[rson] += tag[x]; val[rson] += tag[x];
	tag[x] = 0;
}

void pushup(LL x){
	val[x] = max(val[lson],val[rson]);
}

void modify(LL x,LL l,LL r,LL L,LL R,LL v){
	if(L <= l && r <= R){
		tag[x] += v;
		val[x] += v;
		return;
	}
	pushdown(x,l,r);
	if(L <= mid) modify(lson,l,mid,L,R,v);
	if(R > mid) modify(rson,mid + 1,r,L,R,v);
	pushup(x);
}

LL query(LL x,LL l,LL r,LL L,LL R){
	if(L <= l && r <= R) return val[x];
	pushdown(x,l,r);
	LL ret = -INF;
	if(L <= mid) ret = max(ret,query(lson,l,mid,L,R));
	if(R > mid) ret = max(ret,query(rson,mid + 1,r,L,R));
	pushup(x); return ret;	
}

int main(){
	LL n,m;
	scanf("%lld %lld",&n,&m);
	for(LL i = 1;i <= m;i ++) scanf("%lld %lld %lld",&s[i].l,&s[i].r,&s[i].v);
	sort(s + 1,s + 1 + m,cmp); s[m + 1].r = -1;
	LL sr = 1;
	for(LL i = 1;i <= n;i ++){
		modify(1,1,n,i,i,query(1,1,n,1,i));
		while(s[sr].r == i){
			modify(1,1,n,s[sr].l,s[sr].r,s[sr].v);
			sr ++;
		}
	}
	printf("%lld\n",max(0LL,query(1,1,n,1,n)));
	return 0;
}