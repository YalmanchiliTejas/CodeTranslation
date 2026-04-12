#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
template<typename T>inline bool chkmin(T &x,T y){return (y<x)?(x=y,1):0;}
template<typename T>inline bool chkmax(T &x,T y){return (y>x)?(x=y,1):0;}
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c>'9' || c<'0'));
	if(c=='-') f=-1,c=getchar();
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=2e5+10;
struct point{
	int l,r,v;
	bool operator <(const point &rhs) const{
		return r<rhs.r || (r==rhs.r && l>rhs.l);
	}
}a[maxn];
struct Segment_tree{
	ll Max[maxn<<2],tag[maxn<<2];
	inline void push_down(int x){
		if(tag[x]){
			Max[x<<1]+=tag[x];
			Max[x<<1|1]+=tag[x];
			tag[x<<1]+=tag[x];
			tag[x<<1|1]+=tag[x];
			tag[x]=0;
		}
	}
	inline void push_up(int x){
		Max[x]=max(Max[x<<1],Max[x<<1|1]);
	}
	void update(int x,int L,int R,int ql,int qr,ll v){
		if(ql<=L && R<=qr){
			tag[x]+=v,Max[x]+=v;
			return;
		}
		int Mid=(L+R)>>1;
		push_down(x);
		if(ql<=Mid) update(x<<1,L,Mid,ql,qr,v);
		if(qr>Mid) update(x<<1|1,Mid+1,R,ql,qr,v);
		push_up(x);
	}
	ll query(int x,int L,int R,int ql,int qr){
		if(ql>qr) return 0;
		if(ql<=L && R<=qr) return Max[x];
		int Mid=(L+R)>>1;
		ll res=0;
		push_down(x);
		if(ql<=Mid) chkmax(res,query(x<<1,L,Mid,ql,qr));
		if(qr>Mid) chkmax(res,query(x<<1|1,Mid+1,R,	ql,qr));
		push_up(x);
		return res;
	}
}Seg;
int num[maxn],tmp;
ll sum[maxn],dp[maxn];
int main(){
	int n=read(),m=read();
	REP(i,1,m) a[i].l=read(),a[i].r=read(),a[i].v=read();
	sort(a+1,a+m+1);
	for(int i=1,k=1;i<=n;++i){
		tmp=0;
		num[0]=i;
		while(k<=m && a[k].r==i){
			num[++tmp]=a[k].l,sum[tmp]=a[k].v;
			++k;
		}
		sum[tmp+1]=0;
		DREP(j,tmp,1) sum[j]+=sum[j+1];
		dp[i]=max(Seg.query(1,1,n,1,i-1),0ll)+sum[1];
		REP(j,1,tmp) if(num[j]<num[j-1]) Seg.update(1,1,n,num[j],num[j-1]-1,sum[j]);
		Seg.update(1,1,n,i,i,dp[i]);
	}
	printf("%lld\n",max(Seg.query(1,1,n,1,n),0ll));
	return 0;
}
