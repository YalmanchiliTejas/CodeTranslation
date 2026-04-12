#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<cassert>

using namespace std;

typedef long long ll;

typedef pair<int,pair<pair<int,int>,int>> P;

int di[]={0,-1,0,1};
int dj[]={1,0,-1,0};

int main()
{
	int n,a[3010];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];

	static ll dp[3010][3010];

	for(int i=0;i<n;i++)
		dp[i][i]=a[i]*(n%2==0?-1:1);

	for(int r=2;r<=n;r++)
		for(int i=0;i+r-1<n;i++)
		{
			int j=i+r-1;
			if((n-(j-i+1))%2)
			{
				//JIRO
				dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
			}
			else
			{
				//TARO
				dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
			}
		}

	cout<<dp[0][n-1]<<endl;

	return 0;
}
