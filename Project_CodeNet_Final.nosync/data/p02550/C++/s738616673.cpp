#include<bits/stdc++.h>
#define re register
#define M 998244353
#define int long long
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,k,a[1000002],ans,tim,f[1000002];
char s[1000002];
signed main(){
	n=read();k=read(),m=read();
	while(!a[k]&&tim<=n)a[k]=++tim,f[tim]=f[tim-1]+k,k=k*k%m;
	if(tim==n+1){
		printf("%lld",f[tim-1]);
		return 0;
	}
	ans=f[tim];
	re int xhj=tim-a[k]+1;
	ans+=(f[tim]-f[a[k]-1])*((n-tim)/xhj);
	while((n-tim)%xhj)++tim,ans+=k,k=k*k%m;
	printf("%lld",ans);
}