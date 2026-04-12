#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MX 200005
#define INF 1000000000000000000

int n;
int a[MX];
long long dp[MX][3][3];

long long maxsum(int pos, int taken, int skip)
{
	if(pos >= n)
	{
		if(n&1)
			return (skip == 2) ? -INF : 0;
		else
			return 0;
	}
	long long &ret = dp[pos][taken][skip];
	if(ret != -1)
		return ret;

	if(taken)
	{
		ret = maxsum(pos+1,0,skip);
	}
	else
	{
		if(skip)
		{
			ret = max(a[pos] + maxsum(pos+1,1,skip), maxsum(pos+1,0,skip-1));
		}
		else
		{
			ret = a[pos] + maxsum(pos+1,1,0);
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> a[i];
	memset(dp,-1,sizeof(dp));
	long long ret = (n&1) ? maxsum(0,0,2) : maxsum(0,0,1);
	cout << ret << endl;
}
