#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ch() getchar()
#define pc(x) putchar(x)
template<typename T>inline void read(T&x){
	int f;char c;
	for(f=1,c=ch();c<'0'||c>'9';c=ch())if(c=='-')f=-f;
	for(x=0;c<='9'&&c>='0';c=ch())x=x*10+(c&15);x*=f;
}
template<typename T>inline void write(T x){
	static char q[64];int cnt=0;
	if(!x)pc('0');if(x<0)pc('-'),x=-x;
	while(x)q[cnt++]=x%10+'0',x/=10;
	while(cnt--)pc(q[cnt]);
}
const int maxm=100005;
int vis[maxm],st[maxm];
int main(){
	long long n;int x,m,cx,s=1;read(n),read(x),read(m);
	if(n<=m+1){long long ans=0;for(int i=1;i<=n;++i,x=1ll*x*x%m)ans+=x;write(ans),pc('\n');}
	else{
		for(cx=x,s=1;!vis[cx];++s,cx=1ll*cx*cx%m)st[vis[cx]=s]=cx;long long ans=0;
		for(int i=1,tx=x;i<vis[cx];++i,tx=1ll*tx*tx%m)ans+=tx;n-=vis[cx]-1;
		int len=s-vis[cx];long long tmp=0;for(int i=vis[cx];i<s;++i)tmp+=st[i];
		ans+=(n/len)*tmp;n%=len;for(int i=vis[cx];i<vis[cx]+n;++i)ans+=st[i];
		write(ans),pc('\n');
	}
	return 0;
}
