#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstdlib>
#define LL long long
#define LD long double
using namespace std;
const int NN=8000 +117;
const int MM=200 +117;
int read(){
	int fl=1,x;char c;
	for(c=getchar();(c<'0'||c>'9')&&c!='-';c=getchar());
	if(c=='-'){fl=-1;c=getchar();}
	for(x=0;c>='0'&&c<='9';c=getchar())
		x=(x<<3)+(x<<1)+c-'0';
	return x*fl;
}
void open(){
	freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}


int m,n;
LL fact[NN]={};
LL rev[NN]={};
const int mod=998244353;
LL comp(int n,int m){
	if(m>n)return 0;
	return fact[n]*rev[m]%mod*rev[n-m]%mod;
}
LL ksm(LL a,LL b){
	LL ret=1;
	for(;b;b>>=1,a=a*a%mod)
		if(b&1)ret=ret*a%mod;
	return ret;
}
void prefact(int n){
	fact[0]=1;
	for(int i=1;i<=n;++i)fact[i]=fact[i-1]*i%mod;
	rev[n]=ksm(fact[n],mod-2);
	for(int i=n;i>=1;--i)rev[i-1]=rev[i]*i%mod;
}
LL dp[2][NN]={};
LL a[4*NN]={};
LL b[4*NN]={};
int len=0;
int revb[4*NN]={};
int gt=3;
int revgt;
void dft(LL a[],int len,int sym){
	for(int i=1;i<len;++i)if(revb[i]<i)swap(a[revb[i]],a[i]);
	LL g=(sym==1?gt:revgt);
	for(int d=1;d<len;d<<=1){
		LL e=ksm(g,(mod-1)/d/2);
		for(int st=0,gap=d<<1;st<len;st+=gap){
			LL rt=1;
			for(int k=0;k<d;++k,rt=rt*e%mod){
				LL y=a[st+d+k]*rt;
				a[st+d+k]=(a[st+k]-y)%mod;
				a[st+k]=(a[st+k]+y)%mod;
			}
		}
	}
	if(sym==-1){
		LL bas=ksm(len,mod-2);
		for(int i=0;i<len;++i)
			a[i]=a[i]*bas%mod;
	}
}
int main(){
	//open();
	n=read();
	m=read();
	prefact(n+10);
	dp[0][0]=1;
	int now=0;
	len=1;
	while(len<=2*n)len<<=1;
	for(int i=1;i<len;++i){
		revb[i]=revb[i>>1]>>1;
		if(i&1)revb[i]|=len>>1;
	}
	for(int i=1;i<=n;++i){
		b[i]=rev[i+2];
	}
	revgt=ksm(gt,mod-2);
	dft(b,len,1);
	for(int ti=1;ti<=m;++ti){
		now^=1;
		for(int i=0;i<len;++i)a[i]=0;
		for(int i=0;i<=n;++i){
			a[i]=dp[now^1][i]*rev[i]%mod;
		}
		dft(a,len,1);
		for(int i=0;i<len;++i)a[i]=a[i]*b[i]%mod;
		dft(a,len,-1);
		for(int j=0;j<=n;++j){
			dp[now][j]=a[j]*fact[j+2]%mod;
		}
		for(int j=0;j<=n;++j){
			dp[now][j]+=dp[now^1][j]*(comp(j+1,2)+1);
			dp[now][j]%=mod;
		}
	}
	LL ans=0;
	for(int i=0;i<=n;++i){
		ans=(ans+dp[now][i]*comp(n,i))%mod;
	}
	ans=(ans+mod)%mod;
	printf("%lld\n",ans);
	close();
	return 0;
}