#include <bits/stdc++.h>
using namespace std;

long long n,m;
char str[200005];
int arr[200005];
long long MOD=1000000007;

int main(){
	scanf("%lld%lld",&n,&m);scanf("%s",str);
	for(int i=0;i<m;i++){
		if(str[i]=='R')arr[i]=0;
		else arr[i]=1;
	}
	bool all[2];all[0]=all[1]=1;
	for(int i=0;i<m;i++)all[arr[i]^1]=0;
	if(all[0]||all[1]){
		long long dp[2][n];memset(dp,0,sizeof(dp));
		dp[0][0]=1;dp[1][0]=0; //start with red (or blue if everything is blue)
		for(int i=1;i<n;i++){
			dp[0][i]=dp[0][i-1]+dp[1][i-1];
			dp[1][i]=dp[0][i-1];
			dp[0][i]%=MOD;dp[1][i]%=MOD;
		}
		long long ans=(dp[0][n-1]+dp[1][n-1])%MOD; //end with red or blue
		memset(dp,0,sizeof(dp));
		dp[0][0]=0;dp[1][0]=1; //start with blue
		for(int i=1;i<n;i++){
			dp[0][i]=dp[0][i-1]+dp[1][i-1];
			dp[1][i]=dp[0][i-1];
			dp[0][i]%=MOD;dp[1][i]%=MOD;
		}
		ans+=dp[0][n-1];ans%=MOD;ans+=MOD;ans%=MOD; //only end with red
		printf("%lld",ans);
		return 0;
	}
	if(n%2!=0){printf("0");return 0;}
	long long s=0,l=n-1;
	for(int i=0;i<m;i++){
		long long cur=0;
		while(i+cur<m&&arr[i+cur]==arr[0])cur++;
		if(s==0)s=(cur%2==0?cur+1:cur);
		else if(i+cur<m&&cur%2!=0)l=min(l,cur);
		i+=cur;
	}
	long long mxl=min((s==0?MOD:s),l);
	//comments: wlog red is first
	//can ignore last segment of red
	n/=2; mxl/=2; //remove the ones that are different parity from blue
	long long dp[100100],pref[100100];
	memset(dp,0,sizeof(dp));memset(pref,0,sizeof(pref));
	//i segments on a line, first and last are blue, max mxl consecutive reds
	//blues may be consecutive because the reds in between were removed
	dp[0]=pref[0]=0;dp[1]=pref[1]=1;
	for(long long i=2;i<=n+10;i++){
		dp[i]=pref[i-1]-pref[max(0LL,i-(mxl+2))];
		dp[i]%=MOD;dp[i]+=MOD;dp[i]%=MOD;
		pref[i]=dp[i]+pref[i-1];
		pref[i]%=MOD;pref[i]+=MOD;pref[i]%=MOD;
	}
	long long ans=0;
	for(long long i=2;i<=mxl+2;i++){
		ans+=((i-1LL)*dp[n-i+2])%MOD;
		ans%=MOD;
	}
	ans+=MOD;ans%=MOD;
	printf("%lld",(ans*2LL)%MOD);
}
