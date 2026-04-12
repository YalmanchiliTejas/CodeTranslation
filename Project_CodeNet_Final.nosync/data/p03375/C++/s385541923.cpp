#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=3005;
int n,P,fac[N],ifac[N],inv[N],S[N][N],pw[N],pwpw[N];
int fpow(int k1,int k2,int P=::P){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;
	return k3;
}
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
int main(){
	scanf("%d%d",&n,&P);
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[0]=inv[1]=1;
	rep(i,2,N-1)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	S[0][0]=1;
	rep(i,1,N-1)rep(j,1,N-1)S[i][j]=(S[i-1][j-1]+1LL*S[i-1][j]*j%P)%P;
	rep(i,0,N-1)pw[i]=fpow(2,i),pwpw[i]=fpow(2,fpow(2,i,P-1));
	int ans=0;
	rep(i,0,n){
		int w=1,bs=pw[n-i];
		rep(j,0,i){
			if(j){
				w=1LL*w*bs%P;
			}
			(ans+=(i&1?P-1LL:1LL)*C(n,i)%P*S[i+1][j+1]%P*pwpw[n-i]%P*w%P)%=P;
		}
	}
	printf("%d\n",ans);
	return 0;
}