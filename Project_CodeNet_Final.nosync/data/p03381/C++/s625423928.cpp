#include <stdio.h>
#include <string.h>
#include <algorithm>
#define rep(i,st,ed) for (int i=st;i<=ed;++i)

const int N=400005;

int a[N],b[N],s[N<<2];

int read() {
	int x=0,v=1; char ch=getchar();
	for (;ch<'0'||ch>'9';v=(ch=='-')?(-1):(v),ch=getchar());
	for (;ch<='9'&&ch>='0';x=x*10+ch-'0',ch=getchar());
	return x*v;
}

void modify(int now,int tl,int tr,int x,int v) {
	s[now]+=v; if (tl==tr) return ;
	int mid=(tl+tr)>>1;
	if (x<=mid) modify(now<<1,tl,mid,x,v);
	else modify(now<<1|1,mid+1,tr,x,v);
}

int ask(int now,int tl,int tr,int k) {
	if (tl==tr) return tl;
	int w=s[now<<1],mid=tl+tr>>1;
	if (w>=k) return ask(now<<1,tl,mid,k);
	else return ask(now<<1|1,mid+1,tr,k-w);
}

int main(void) {
	int n=read();
	rep(i,1,n) b[i]=a[i]=read();
	std:: sort(b+1,b+n+1);
	int size=std:: unique(b+1,b+n+1)-b-1;
	rep(i,1,n) a[i]=std:: lower_bound(b+1,b+size+1,a[i])-b;
	rep(i,1,n) modify(1,1,size,a[i],1);
	rep(i,1,n) {
		modify(1,1,size,a[i],-1);
		printf("%d\n", b[ask(1,1,size,n/2)]);
		modify(1,1,size,a[i],1);
	}
	return 0;
}