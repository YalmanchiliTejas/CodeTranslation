#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long

#define file_io 0

ll i,j,md=1e9+7;
ll k,n,a[10005],lens,dp[10005][105];
char s[10005];

ll dfs(int pos,int sum,bool limit) {
	if(pos==lens+1) return dp[pos][sum] = (sum==0);

	if(limit==0 && dp[pos][sum] != -1) return dp[pos][sum];

	//12345, tried 123AB, A must <=4, limited
	//otherwise, A<=9
	int up=limit ? a[pos] : 9;
	ll newsum = 0;

	int t;
	for(t=0; t<=up; ++t) {
		newsum+=dfs(pos+1,(sum+t)%k,limit&&t==up);
		if(newsum>=md) newsum-=md;
	}

	if(limit==0) dp[pos][sum] = newsum;
	return newsum;
}

int main() {
	if (file_io) {
		freopen(".in","r",stdin);
		freopen(".out","w",stdout);
	}

	scanf("%s%lld",s+1,&k);

	memset(dp,-1,sizeof(dp));

	lens=strlen(s+1);
	for (i=1; i<=lens; ++i) {
		a[i]=(int)s[i]-48;
	}

	printf("%lld\n",(dfs(1,0,1)-1+md)%md);

	return 0;
}