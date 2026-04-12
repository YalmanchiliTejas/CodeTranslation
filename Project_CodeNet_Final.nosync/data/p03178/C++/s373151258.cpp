#include <iostream>
#define mod 1000000007
using namespace std;
int dp[10005][105][2];
int main(int argc, char** argv) {
	string a;
	cin >> a;
	int d,n=a.size();
	cin >> d;
	a=' '+a;
	for(int i=1;i<=n;i++)
		a[i]-='0';
	dp[0][0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<d;j++)
		{
			for(int k=0;k<10;k++)
			{
				dp[i][(j+k)%d][0]+=dp[i-1][j][0];
				if(k<a[i]) dp[i][(j+k)%d][0]+=dp[i-1][j][1];
				if(k==a[i]) dp[i][(j+k)%d][1]+=dp[i-1][j][1];
				dp[i][(j+k)%d][0]%=mod;
			}
		}
	}
	cout << (dp[n][0][0]+dp[n][0][1]+mod-1)%mod;
	return 0;
}