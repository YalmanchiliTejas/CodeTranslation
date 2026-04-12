#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
int solve(){
	int d,n;
	string s;
	cin>>s>>d;
	n=s.size();//first solve for n-1 digits upperbound is 9;
	long long dp[n][d];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<d;j++){
			for(int x=0;x<=9;x++){
				dp[i][(j+x)%d]=(dp[i][(j+x)%d]+dp[i-1][j])%M;
			}
		}
	}
	long long ans=M-1; //subtracting 1 for zero;
	int t=0;
	for(int i=0;i<n;i++){
		for(int x=0;x<(s[i]-'0');x++){
			ans=(ans+(dp[n-i-1][(d-(x+t)%d)%d]))%M;
		}
		t+=(s[i]-'0');
	}
	if(t%d==0) ans++;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve();
	
}