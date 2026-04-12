#include <bits/stdc++.h>
using namespace std;
const int maxn=3005;
long long c[maxn][maxn],s2[maxn][maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
long long power(long long x,long long b,long long mod){
	long long ans=1;
	while(b){
		if(b&1)ans=ans*x%mod;
		x=x*x%mod;
		b>>=1;
	}
	return ans;
}
int main(){
//    freopen("AT4119.in","r",stdin);
//    freopen("AT4119.out","w",stdout);
   	int n,m;
	n=read();m=read();
	c[0][0]=1;
	for(int i=1;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%m;
	}
	s2[0][0]=1;
	for(int i=1;i<=n+1;i++){
		s2[i][0]=0;
		for(int j=1;j<=i;j++)
			s2[i][j]=(s2[i-1][j]*j%m+s2[i-1][j-1])%m;
	}
	long long ans=0,op=1;
	for(int i=0;i<=n;i++){
		long long cur=c[n][i]*power(2,power(2,n-i,m-1),m)%m;
		long long sum=0;
		for(int j=0;j<=i;j++)
			sum=(sum+s2[i+1][j+1]*power(2,j*(n-i),m)%m)%m;
		ans=(ans+op*cur*sum%m+m)%m;
		op=-op;
	}
	printf("%lld\n",ans);
    return 0;
}
