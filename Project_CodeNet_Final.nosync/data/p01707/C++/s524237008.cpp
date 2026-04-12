#include<stdio.h>
#include<algorithm>
using namespace std;
long long mod=1000000007;
long long C[2100][2100];
long long dp[2100][2100];
long long sum[2100][2100];
long long inv[2100];
long long calc(long long a,int b){
	long long ret=1;
	for(int i=0;i<b;i++){
		ret=(a-i)%mod*ret%mod*inv[i+1]%mod;
	}
	return ret;
}
int main(){
	int a;
	long long b;
	int c;
	C[0][0]=1;
	for(int i=0;i<2050;i++){
		for(int j=0;j<=i;j++){
			C[i+1][j]=(C[i+1][j]+C[i][j])%mod;
			C[i+1][j+1]=(C[i+1][j+1]+C[i][j])%mod;
		}
	}
	inv[1]=1;
	for(int i=2;i<2050;i++){
		inv[i]=(mod-inv[mod%i]*(mod/i)%mod)%mod;
	}
	while(scanf("%d%lld%d",&a,&b,&c),a){
	c--;
		for(int i=0;i<=a;i++)for(int j=0;j<=a;j++)dp[i][j]=sum[i][j]=0;
		dp[0][0]=1;
		for(int i=0;i<=a;i++)sum[0][i]=1;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=a;j++){
				long long val=sum[i-1][j-1];
				if(j-c-1>=0)val=(val+mod-sum[i-1][j-c-1])%mod;
				dp[i][j]=val;
		//		printf("%d %d: %lld\n",i,j,val);
			}
			sum[i][0]=dp[i][0];
			for(int j=1;j<=a;j++){
				sum[i][j]=(sum[i][j-1]+dp[i][j])%mod;
			}
		}
		
		long long ret=0;
		for(int i=1;i<=min((long long)a,b);i++){
			ret=(ret+calc(b,i)*dp[i][a])%mod;
		}
		printf("%lld\n",ret);
	}
}