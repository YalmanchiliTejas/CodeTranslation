#include <bits/stdc++.h>
#define re register
#define SIZE 3005
#define LL long long
using namespace std;
int n;
LL a[SIZE],dp[SIZE][SIZE];
int main()
{
	cin>>n;
	for(re int i=1;i<=n;++i)
		cin>>a[i],dp[i][i]=a[i];
	for(re int len=1;len<=n;++len)
		for(re int l=1;l<n;++l)
		{
			int r=l+len-1;
			if(r>n)
				break;
			dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
		}
	cout<<dp[1][n]<<endl;
	return 0;
} 