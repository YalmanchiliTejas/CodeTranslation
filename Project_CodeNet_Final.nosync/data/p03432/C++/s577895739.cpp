#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=20005,L=205,M=998244353;
int dp[L][N],fac[N],inv[N],a[N],b[N],n,m;
int C(int x,int y){
	if (x<y)return 0;
	return fac[x]*inv[y]%M*inv[x-y]%M;
}
int ksm(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=x*x%M)
		if (y&1)(ans*=x)%=M;
	return ans;
}
void init(int y[],int len){
	for (int i=1,j=len/2;i<len-1;i++){
		if (i<j)swap(y[i],y[j]);
		int k=len/2;
		while (j>=k){
			j-=k;
			k/=2;
		}
		j+=k;
	}
}
void ntt(int y[],int len,int opt){
	init(y,len);
	for (int h=2;h<=len;h<<=1){
		int wn=ksm(3,(M-1)/h);
		if (opt==-1)wn=ksm(wn,M-2);
		for (int j=0;j<len;j+=h){
			int w=1;
			for (int k=j;k<j+h/2;k++){
				int u=y[k],v=y[k+h/2]*w%M;
				y[k]=(u+v)%M;
				y[k+h/2]=(M+u-v)%M;
				w=w*wn%M;
			}
		}
	}
	if (opt==1)return;
	int temp=ksm(len,M-2);
	for (int i=0;i<len;i++)(y[i]*=temp)%=M;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	fac[0]=inv[0]=1;
	for (int i=1;i<N;i++)fac[i]=fac[i-1]*i%M,inv[i]=ksm(fac[i],M-2);
	int len=1;
	while (len<2*n+100)len<<=1;
	dp[0][0]=1;
	for (int j=1;j<=m;j++){
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for (int i=1;i<=n;i++)b[i]=inv[i+2];
		for (int i=0;i<=n;i++)a[i]=dp[j-1][i]*inv[i]%M;
		ntt(a,len,1);ntt(b,len,1);
		for (int i=0;i<len;i++)(a[i]*=b[i])%=M;
		ntt(a,len,-1);
		for (int i=0;i<=n;i++)dp[j][i]=a[i]*fac[i+2]%M;
		for (int i=0;i<=n;i++)(dp[j][i]+=dp[j-1][i]*(i*(i+1)/2+1))%=M;
	}
	int ans=0;
	for (int i=0;i<=n;i++)(ans+=C(n,i)*dp[m][i])%=M;
	printf("%lld\n",ans);
}
