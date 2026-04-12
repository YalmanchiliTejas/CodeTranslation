#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

int k;
int aa[110];
int dp[110][5];

int dfs(int pos, int cnt, bool limit)//state标记上一位是不是6 是6我们需要进行特判了
{
    if(cnt<0)   return 0;
	if (pos == 0 && cnt == 0)  return 1;
	//处理完数字个位 表明这个车牌是可以用的 可以先往下看
	//这毕竟是一个递归出口直接看容易晕
	//!limit 是因为当我们处理到limit时 处理方法不一样
	if (!limit&& dp[pos][cnt] != -1) //如果这一位开头的已经处理过了 直接返回结果就行
		return dp[pos][cnt];
	int up = limit ? aa[pos] : 9;
	//limint为假时下一位最高位为9 比如我们处理3xx的时候limit一直假
	int  ans = 0;
	for (int i = 0; i <= up; i++)
	{
        ans += dfs(pos - 1, cnt- (i != 0), limit && i == up);
			//这一位是不是最高位且上一位是不是取到最高位
			//为什么要看前一位是不是最高位呢 我们看处理三百二十里面有多少满足条件的时候肯定320-329都要看看  因为整个300-399都是小于525的
	}
	if (!limit) //不是最高位就记录
		dp[pos][cnt] = ans;//对此为的结果进行记录 方便以后再次利用
	//注意state是因为这一位是不是6 影响着后面的结果
	// return到最后返回了每一位的值
	return ans;
}
int solve(string s)
{
	int n = s.size();//s记录t的位数
    for(int i=0;i<n;++i){
        aa[n-i] = s[i]-'0';
    }
	// while (t != 0)
	// {
	// 	aa[++s] = t % 10;
	// 	t /= 10;
	// }
	return dfs(n, k, true);
}
int main()
{
    string s;
	memset(dp, -1, sizeof(dp));
    cin >> s >> k;
    cout << solve(s)<< endl;
}
