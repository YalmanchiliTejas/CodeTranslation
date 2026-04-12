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
const int N=2e5+5,P=1e9+7;
inline void upd(R int &x,R int y){(x+=y)>=P?x-=P:0;}
inline int add(R int x,R int y){return x+y>=P?x+y-P:x+y;}
inline int dec(R int x,R int y){return x-y<0?x-y+P:x-y;}
inline int mul(R int x,R int y){return 1ll*x*y-1ll*x*y/P*P;}
char s[N];int f[N],dp[2][5],n,m,res,t;
void solve1(){
	dp[0][0]=dp[0][3]=1,t=0;
	for(R int i=1;i<n;++i,t^=1){
		dp[t^1][0]=dp[t^1][1]=dp[t^1][2]=dp[t^1][3]=0;
		dp[t^1][0]=add(dp[t][0],dp[t][1]),
		dp[t^1][1]=dp[t][0],
		dp[t^1][2]=add(dp[t][2],dp[t][3]),
		dp[t^1][3]=dp[t][2];
	}
	res=add(dp[t][0],add(dp[t][1],dp[t][2]));
	printf("%d\n",res);
}
void solve2(){
	int lim=n,cur=0,las=m;
	while(s[las]=='R')--las;
	fd(i,las,1)if(s[i]=='B'){
		if(cur&1)cmin(lim,cur+1);
		cur=0;
	}else ++cur;
	cmin(lim,cur+1+(cur&1^1));
	f[0]=f[2]=1;
	for(R int i=4;i<=n;i+=2){
		f[i]=mul(f[i-2],2);
		if(i>=lim+2)f[i]=dec(f[i],f[i-(lim+2)]);
	}
	res=0;
	for(R int i=2;i<=lim;i+=2)upd(res,mul(f[n-i],i));
	printf("%d\n",res);
}
int main(){
//	freopen("testdata.in","r",stdin);
	scanf("%d%d%s",&n,&m,s+1);
	if(s[1]=='B')fp(i,1,m)s[i]^='B'^'R';
	bool flag=0;
	fp(i,1,m)if(s[i]=='B'){flag=1;break;}
	if(!flag)solve1();else solve2();
	return 0;
}