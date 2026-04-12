#include<iostream>
#include<cstdio>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int N = 2e5+5;
const int inf = 0x3f3f3f3f;
vector<int>VR,VG,VB;
ll a[N],dp[N],sum[N];
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	sum[i]=(i>1?sum[i-2]:0)+a[i];
	for(int i=2;i<=n;i++)
	{
		if(i&1)dp[i]=max(a[i]+dp[i-2],dp[i-1]);
		else dp[i]=max(a[i]+dp[i-2],sum[i-1]);
	}
	cout<<dp[n];
	return 0;
}