#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9+7;
const int N = 1e6+5;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string k;
	cin>>k;
	int d;
	cin>>d;
	int n = k.length();
	int dp[n+1][d];
	memset(dp, 0, sizeof(dp));
	dp[0][0]=0;
	int pm = 0;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<k[i-1]-'0';j++) {
			dp[i][(pm+j)%d]++;
		}
		pm=(pm+k[i-1]-'0')%d;
		for(int j=0;j<d;j++) {
			for(int num=0;num<10;num++) {
				dp[i][(j+num)%d]+=dp[i-1][j];
				dp[i][(j+num)%d]%=MOD;
			}
		}
	}	
	if(pm==0) {
		dp[n][0]++;
	}
	cout<<(dp[n][0]+MOD-1)%MOD;

	return 0;
}