#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e4+5;
const ll mod = 1e9+7;
char s[maxn];
int arr[maxn];
int d,len;
ll dp[maxn][105][2];
ll getdp(int pos,int cur,int lim){
	if(pos == len +1 ){
		if(!cur) dp[pos][cur][lim] = 1;
		else dp[pos][cur][lim] = 0;
		return dp[pos][cur][lim];
	}
	if(dp[pos][cur][lim]!=-1) return dp[pos][cur][lim];
	int up = lim?arr[pos]:9;
	ll sum = 0;
	for (int i = 0; i <=up; ++i)
	{
		sum+=getdp(pos+1,(cur+i)%d,lim && i == up);
		sum%=mod;
		/* code */
	}
	dp[pos][cur][lim] = sum;
	return sum;
}
int main() {
	scanf("%s",s+1);
	scanf("%d",&d);
	len = strlen(s+1);
	for (int i = 1; i <=len; ++i)
	{
		arr[i] = s[i] - '0';
		/* code */
	}
	memset(dp,-1,sizeof(dp));
	ll ans = getdp(1,0,1);
	printf("%lld\n",(ans-1+mod)%mod);
	return 0;
}