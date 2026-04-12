#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline char tc(void){
	static char fl[10000],*A=fl,*B=fl;
	return A==B&&(B=(A=fl)+fread(fl,1,10000,stdin),A==B)?EOF:*A++;
}
inline int read(void){
	int a=0;char c;
	while((c=tc())<'0'||c>'9');
	while(c>='0'&&c<='9')a=a*10+c-'0',c=tc();
	return a;
}
int n,sum[200001],s[200001],h[200001],cnt;
inline void add(int x,int y){
	while(x<=n)sum[x]+=y,x+=x&-x;
}
inline int query(int x){
	int res=0;
	while(x)res+=sum[x],x-=x&-x;
	return res;
}
int main(void){
	register int i,mid,l,r;
	n=read();
	for(i=1;i<=n;++i)s[i]=h[i]=read();
	sort(h+1,h+n+1),cnt=unique(h+1,h+n+1)-h-1;
	for(i=1;i<=n;++i)s[i]=lower_bound(h+1,h+cnt+1,s[i])-h,add(s[i],1);
	for(i=1;i<=n;++i){
		add(s[i],-1);
		l=1,r=cnt;
		while(l<=r){
			mid=l+r>>1;
			if(query(mid)<(n>>1))l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",h[l]);
		add(s[i],1);
	}
	return 0;
}