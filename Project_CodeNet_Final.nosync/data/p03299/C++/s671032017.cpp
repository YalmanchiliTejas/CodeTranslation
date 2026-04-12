#include<bits/stdc++.h>
using namespace std;

#define INF int(1e9+5)
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=105;
const int mod=1e9+7;
int n;
int h[maxn],dp[maxn][maxn][3];

int quickpow(int x,int pow){
	int res=1;
	for(;pow;pow>>=1){
		if(pow&1)res=1LL*res*x%mod;
		x=1LL*x*x%mod;
	}
	return res;
}

void solve(int l,int r,int last){
	dp[l][r][0]=dp[l][r][1]=dp[l][r][2]=1;
	int mn=INF;
	for(int i=l;i<=r;i++)mn=min(mn,h[i]);
	int cnt=0;
	for(int i=l;i<=r;i++){
		if(h[i]==mn)cnt++;
		else{
			int j=i;
			while(j<=r&&h[j]>mn)j++;
			solve(i,j-1,mn-1);
			dp[l][r][0]=1LL*dp[l][r][0]*dp[i][j-1][(i-l)&1]%mod;
			dp[l][r][1]=1LL*dp[l][r][1]*dp[i][j-1][1^((i-l)&1)]%mod;
			dp[l][r][2]=1LL*dp[l][r][2]*dp[i][j-1][2]%mod;
			i=j-1; 
		}
	}
	int cur=dp[l][r][0]+dp[l][r][1];
	if(cur>=mod)cur-=mod;
	dp[l][r][2]=1LL*dp[l][r][2]*quickpow(2,cnt)%mod;
	dp[l][r][2]-=cur;
	if(dp[l][r][2]<0)dp[l][r][2]+=mod;
	if(mn-last>1)dp[l][r][0]=dp[l][r][1]=1LL*cur*quickpow(2,mn-last-2)%mod;
	rep(i,2){
		dp[l][r][2]+=dp[l][r][i];
		if(dp[l][r][2]>=mod)dp[l][r][2]-=mod;
	}
} 

int main(){
	scanf("%d",&n);
	REP(i,n)scanf("%d",&h[i]);
	solve(1,n,0);
	printf("%d\n",dp[1][n][2]);
	return 0;
}