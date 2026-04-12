#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll INF = (ll)1<<62;
const ll MOD = 1e9+7;

ll dp[100005][105][2];

int main(){
	string k;
	int d;
	cin>>k;
	cin>>d;
	int n = k.size();
	for(int rem=1;rem<d;rem++){
		dp[n][rem][0] = dp[n][rem][1] = 0; 
	}
	dp[n][0][0] = dp[n][0][1] = 1;
	for(int i=n-1;i>=0;i--){
		for(int rem=0;rem<d;rem++){
			dp[i][rem][0] = dp[i][rem][1] = 0;
			for(int j=0;j<=9;j++){
				dp[i][rem][1] = (dp[i][rem][1]+dp[i+1][(rem+j)%d][1])%MOD;
				if(j<k[i]-'0')
					dp[i][rem][0] = (dp[i][rem][0]+dp[i+1][(rem+j)%d][1])%MOD;
				else if(j==k[i]-'0')
					dp[i][rem][0] = (dp[i][rem][0]+dp[i+1][(rem+j)%d][0])%MOD;	
			}
		}
	}
	cout<<(dp[0][0][0]-1+MOD)%MOD<<"\n";
	return 0;
}

/*
dp[i][rem][0] = No. of ways to put the digits in such a way that their sum%D is D-rem such that digits put till now are matching with s.
dp[i][rem][1] = No. of ways to put the digits in such a way that their sum%D is D-rem
*/