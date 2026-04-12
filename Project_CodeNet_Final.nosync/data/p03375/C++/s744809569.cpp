#include<bits/stdc++.h>
const int N=3003;
using namespace std;
int n,M,tp,c[N][N],s[N][N],
ans,sum,ss;
inline int ksm(long long x,int t,int m=M){
	int y=1;
	for(;t;t>>=1)
	t&1?y=y*x%m:0,x=x*x%m;
	return y;
}
int main(){
	scanf("%d%d",&n,&M);
	s[0][0]=1;
	for(int i=0;i<=n;i++){
		c[i][0]=1;
		for(int j=1;j<=i;j++)
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%M,
		s[i][j]=(s[i-1][j-1]+s[i-1][j]*1ll*j)%M;
	}
	for(int i=0;i<=n;i++){
		ss=1,sum=0,tp=ksm(2,n-i);
		for(int j=0;j<=i;j++){
			sum=(sum+(s[i][j]+(j+1ll)*s[i][j+1])%M*ss)%M;
			ss=ss*1ll*tp%M;
		}
		ans=(ans+(i&1?-1ll:1ll)*c[n][i]%M*sum%M*ksm(2,ksm(2,n-i,M-1)))%M;
	}
	printf("%d",(M+ans)%M);
}