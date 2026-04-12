#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define qmax(x,y) (x=max(x,y))
#define qmin(x,y) (x=min(x,y))
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0,fh=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') fh=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		ans=ans*10+ch-'0',ch=getchar();
	return ans*fh;
}
const int maxn=2e5+100,inf=1e9;
struct node{
	int x,y;
}a[maxn];
#define lc (o<<1)
#define rc (o<<1|1)
int n,lx,ln,rx,rn=inf,px[maxn<<2],pn[maxn<<2];
ll Ans=1e18;
bool cmp(node x,node y){return x.x==y.x?x.y>y.y:x.x>y.x;}
void build(int o,int l,int r){
	if(l==r){px[o]=pn[o]=a[l].y;return;}
	int mid=l+r>>1;
	build(lc,l,mid),build(rc,mid+1,r);
	px[o]=max(px[lc],px[rc]);
	pn[o]=min(pn[lc],pn[rc]);
}
int qmx(int o,int l,int r,int ql,int qr){
	if(ql==l&&qr==r){return px[o];}
	int mid=l+r>>1,ans=0;
	if(ql<=mid) ans=qmx(lc,l,mid,ql,min(qr,mid));
	if(qr>mid) qmax(ans,qmx(rc,mid+1,r,max(ql,mid+1),qr));
	return ans;
}
int qmn(int o,int l,int r,int ql,int qr){
	if(ql==l&&qr==r){return pn[o];}
	int mid=l+r>>1,ans=0x7fffffff;
	if(ql<=mid) ans=qmn(lc,l,mid,ql,min(qr,mid));
	if(qr>mid) qmin(ans,qmn(rc,mid+1,r,max(ql,mid+1),qr));
	return ans;
}
int main(){
//	freopen("nh.in","r",stdin);
//	freopen("zhy.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read(),a[i].y=read();
		if(a[i].x<a[i].y) swap(a[i].x,a[i].y);
		rn=min(rn,a[i].y);
	}
	for(int i=1;i<=n;i++)
		if(a[i].y==rn) swap(a[i],a[n]);
	sort(a+1,a+n,cmp),build(1,1,n);
	for(int i=1;i<n;i++){
		rx=a[1].x;
		lx=max(a[n].x,max(qmx(1,1,n,1,i),a[i+1].x));
		ln=min(a[n].x,min(qmn(1,1,n,1,i),i==n-1?inf:a[n-1].x));
		qmin(Ans,1ll*(rx-rn)*(lx-ln));
	}
	for(int i=1;i<n;i++){
		lx=max(a[n].x,a[1].x);
		rx=max(qmx(1,1,n,1,i),i==n-1?0:a[i+1].x);
		ln=min(a[n].x,min(i==n-1?inf:a[i+1].y,i==n-2?inf:a[n-1].x));
		qmin(Ans,1ll*(rx-rn)*(lx-ln));
	}
	printf("%lld\n",Ans);
	return 0;
}










