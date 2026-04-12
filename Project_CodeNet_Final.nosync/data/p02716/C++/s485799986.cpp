#include <bits/stdc++.h>
using namespace std;
int n,a[200005];
map<int,long long> dp[200005];
long long solve(int idx,int cnt)
{
	if (idx>=n)
	{
		if (cnt==n/2)
		return 0;
		return -1e18;
	}
	if (dp[idx].count(cnt))
	return dp[idx][cnt];
	if (cnt+(n-idx+1)/2<n/2)
	return -1e18;
	return dp[idx][cnt]=max(solve(idx+1,cnt),solve(idx+2,cnt+1)+a[idx]);
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("%lld",solve(0,0));
}