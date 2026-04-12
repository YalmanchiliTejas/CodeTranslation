#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll INF_ll=4611686018427387903;
int n,m,now;ll tag[N<<2],seg[N<<2];
struct Interval{int l,r,x;bool operator <(const Interval&e)const{return r<e.r;}}a[N];
inline void pushdown(int o,int L,int R){
	if(tag[o]){
		int lc=o<<1,rc=(o<<1)+1;
		tag[lc]+=tag[o];tag[rc]+=tag[o];
		seg[lc]+=tag[o];seg[rc]+=tag[o];
		tag[o]=0;
	}
}
inline void update(int o,int L,int R,int l,int r,ll x){
	if(l<=L&&R<=r){tag[o]+=x;seg[o]+=x;return;}
	int M=(L+R)>>1,lc=o<<1,rc=(o<<1)+1;
	pushdown(o,L,R);
	if(l<=M)update(lc,L,M,l,r,x);
	if(r>M)update(rc,M+1,R,l,r,x);
	seg[o]=max(seg[lc],seg[rc]);
}
inline ll query(int o,int L,int R,int l,int r){
	if(l<=L&&R<=r)return seg[o];
	int M=(L+R)>>1,lc=o<<1,rc=(o<<1)+1;ll sum=-INF_ll;
	pushdown(o,L,R);
	if(l<=M)sum=max(sum,query(lc,L,M,l,r));
	if(r>M)sum=max(sum,query(rc,M+1,R,l,r));
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(register int i=1;i<=m;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].x);
	sort(a+1,a+m+1);now=1;
	for(register int i=1;i<=n;i++){
		update(1,1,n,i,i,query(1,1,n,1,i));
		while(a[now].r==i&&now<=m)update(1,1,n,a[now].l,a[now].r,a[now].x),now++;
	}
	printf("%lld\n",max(0ll,seg[1]));
	return 0;
}