//minamoto
#include<bits/stdc++.h>
#define R register
#define inline __inline__ __attribute__((always_inline))
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=3005;
typedef long long ll;
ll s[N][N];int a[N],n,t;
int main(){
	scanf("%d",&n),t=n&1;
	fp(i,1,n)scanf("%d",&a[i]),s[i][i]=t?a[i]:-a[i];
	fp(k,2,n)if((k&1)==t)for(R int i=1,j=k;j<=n;++i,++j)s[i][j]=max(s[i+1][j]+a[i],s[i][j-1]+a[j]);
	else for(R int i=1,j=k;j<=n;++i,++j)s[i][j]=min(s[i+1][j]-a[i],s[i][j-1]-a[j]);
	printf("%lld\n",s[1][n]);
	return 0;
}