
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll dp[N][2],arr[N];
void solve()
{
	int n;
	cin >> n;

	for (int i = 1; i < n + 1; i++)
		cin >> arr[i];
	memset(dp, 0, sizeof(dp));
	dp[2][1] = arr[2];
	dp[2][0] = arr[1];
	for (int i = 3; i < n + 1; i++)
	{
		if (i & 1)
		{
			ll temp = max({dp[i-3][1],dp[i-3][0],dp[i-2][1],dp[i-2][0]});
			//位置i选择
			//i：x个
			//i-1 x个
			//i-2：x-1个
			//i-3：x-1个
			//i-4: x-2个
			dp[i][1] = arr[i] + temp;

			dp[i][0]=max({dp[i-1][1],dp[i-1][0],arr[i-2]+dp[i-3][0]});
			//arr[i-3]+dp[i-2][1] :不合法
			//该位置不选，从x继承dp[i-1]
			//i-1：x个
			//i-2：x-1个
			//i-3: x-1个
		}
		else
		{
			dp[i][1]=arr[i]+max({dp[i-2][1],dp[i-2][0],dp[i-1][0]});
			//选当前位置 x=i/2
			//i-1:x-1个
			//i-2:x-1个


			//位置i不选，从x位置转移 由于没有x位置
			//i-1:x-1个
			//i-2 x-1个
			//i-3：x-2个
			//结论：一定选i-1  维护前i个必须选i/2个的特性
			dp[i][0] = arr[i-1]+dp[i-2][0];
		}
	}
	cout << max(dp[n][1], dp[n][0]) << endl;
	return;
}

int main()
{
	solve();
	return 0;
}
/*
没有两个相邻的被选上
8
1 2 3 4 -1 -2 -3 -4
*/
