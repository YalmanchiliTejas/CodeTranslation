//minamoto
#include<bits/stdc++.h>
#define R register
#define fp(i,a,b) for(R int i=(a),I=(b)+1;i<I;++i)
#define fd(i,a,b) for(R int i=(a),I=(b)-1;i>I;--i)
#define go(u) for(int i=head[u],v=e[i].v;i;i=e[i].nx,v=e[i].v)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
int P;
inline void upd(R int &x,R int y){(x+=y)>=P?x-=P:0;}
inline int inc(R int x,R int y){return x+y>=P?x+y-P:x+y;}
inline int dec(R int x,R int y){return x-y<0?x-y+P:x-y;}
inline int mul(R int x,R int y,R int P){return 1ll*x*y-1ll*x*y/P*P;}
int ksm(R int x,R int y,R int P){
	R int res=1;
	for(;y;y>>=1,x=mul(x,x,P))(y&1)?res=mul(res,x,P):0;
	return res;
}
const int N=3005;
int c[N][N],s[N][N],n,res;
void init(){
	s[0][0]=c[0][0]=1;
	fp(i,1,n+1){
		c[i][0]=1;
		fp(j,1,i){
			c[i][j]=inc(c[i-1][j],c[i-1][j-1]);
			s[i][j]=(1ll*j*s[i-1][j]+s[i-1][j-1])%P;
		}
	}
}
int main(){
//	freopen("testdata.in","r",stdin);
	scanf("%d%d",&n,&P);
	init();
	fp(i,0,n){
		R int ret=0,fn=ksm(2,ksm(2,n-i,P-1),P),bs=ksm(2,n-i,P);
		fp(j,0,i)upd(ret,1ll*s[i+1][j+1]*fn%P),fn=1ll*fn*bs%P;
		ret=1ll*ret*c[n][i]%P;
		upd(res,i&1?P-ret:ret);
	}
	printf("%d\n",res);
	return 0;
}