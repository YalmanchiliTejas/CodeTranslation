#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
//const long long mod=1000000007;
//const long long inf=mod*mod;
//const long long d2=(mod+1)/2;
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}

long long mod;
long long fact[11000];
long long inv[11000];
long long finv[11000];
long long C(int a,int b){
	if(a<0||a<b)return 0;
	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
long long pw(long long a,long long b,long long c){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%c;
		a=a*a%c;
		b/=2;
	}
	return ret;
}
long long dp[3100][3100];
long long pc[3100];
int main(){
	int a;
	scanf("%d%lld",&a,&mod);
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<11000;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<11000;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	for(int i=0;i<=a;i++){
		pc[i]=pw(2,pw(2,a-i,mod-1),mod);
	}
	dp[0][0]=1;
	for(int i=0;i<a;i++){
		for(int j=0;j<=i;j++){
			if(dp[i][j]==0)continue;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j]*(j+1))%mod;
			dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%mod;
		}
	}
	long long ret=0;
	for(int i=0;i<=a;i++){
		long long ks=C(a,i);
		long long tmp=0;
		for(int j=0;j<=i;j++){
			tmp=(tmp+dp[i][j]*pw(2,(a-i)*j,mod)%mod*pc[i])%mod;
		}
		if(i%2==0){
			ret=(ret+tmp*ks)%mod;
		}else{
			ret=(ret+mod-tmp*ks%mod)%mod;
		}
	}
	printf("%lld\n",ret);
}
