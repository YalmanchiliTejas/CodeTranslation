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
const int NN=5000 +117;
const int MM=4000 +117;
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
LL s[NN][NN]={};
LL mi[NN]={};
LL fact[NN]={};
LL rev[NN]={};
int mod;
LL comp(LL n,LL m){
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
	for(int i=n;i>=1;--i)
		rev[i-1]=rev[i]*i%mod;
}
LL ding[NN]={};
int main(){
	//open();
	n=read();
	mod=read();
	prefact(n);
	s[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			s[i][j]=s[i-1][j-1]+s[i-1][j]*j;
			s[i][j]%=mod;
		}
	}
	mi[0]=1;
	ding[0]=1;
	for(int i=1;i<=n;++i){
		mi[i]=mi[i-1]*2%mod;
		ding[i]=ding[i-1]*2%(mod-1);
	}
	LL ans=0;
	for(int k=0;k<=n;++k){
		LL res=0;
		LL mimi=ksm(2,ding[n-k]);
		for(int j=0;j<=k;++j,mimi=mimi*mi[n-k]%mod){
			res+=(s[k][j+1]*(j+1)+s[k][j])%mod*mimi;
			res%=mod;
		}
		res*=comp(n,k);
		if(k&1)res*=-1;
		res%=mod;
		ans=(ans+res)%mod;
	}
	ans=(ans+mod)%mod;
	printf("%lld\n",ans);
	close();
	return 0;
}