#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;


int main()
{
	int n;
	const int num=3000;
	long long a[num]={};
	long long dp[num][num]={};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
		dp[i][0]=a[i];
	for(int i=1;i<n;i++)//iは残りの前と後ろ番号の差
	{
		for(int j=0;i+j<n;j++)//jは前の番号
		{
			dp[j][i]=a[j+i]-dp[j][i-1];
			if(j<n-1)
				dp[j][i]=max(dp[j][i],a[j]-dp[j+1][i-1]);
		}
	}
	cout<<dp[0][n-1]<<endl;
}
	