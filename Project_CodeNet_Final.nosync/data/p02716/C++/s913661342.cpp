#include <bits/stdc++.h>

#define FOR(a,b,c) for (int a=(b);a<(c);++a)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define lf double

using namespace std;

const int MAX = (int)1e6 + 5;
const ll INF = (ll)1e18;

int p[MAX];
ll dp[MAX][3];

ll f(int x,int y){
	if (x<0) return 0;
	return dp[x][y];
}

int main(){
	int n;
	scanf ("%d",&n);
	REP(i,n){
		scanf ("%d",p+i);
	}
	REP(i,n) REP(j,3) dp[i][j]=-INF;
	dp[0][0]=p[0];
	dp[1][1]=p[1];
	FOR(i,2,n){
		int a=p[i];
		dp[i][0]=max(dp[i][0],f(i-2,0)+a);
		dp[i][1]=max(dp[i][1],f(i-2,1)+a);
		dp[i][1]=max(dp[i][1],f(i-3,0)+a);
		dp[i][2]=max(dp[i][2],f(i-2,2)+a);
		dp[i][2]=max(dp[i][2],f(i-3,1)+a);
		dp[i][2]=max(dp[i][2],f(i-4,0)+a);
		
	}
	if (n&1){
		ll sol=dp[n-1][2];
		sol=max(sol,dp[n-2][1]);
		sol=max(sol,dp[n-3][0]);
		printf ("%lld\n",sol);
	}
	else{
		ll sol=dp[n-1][1];
		sol=max(sol,dp[n-2][0]);
		printf ("%lld\n",sol);
		
	}
	
	
	return 0;
}
