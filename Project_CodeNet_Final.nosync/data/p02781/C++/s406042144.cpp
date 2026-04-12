#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
const int maxb = 200;
const int maxd = 200;
vector<int> bit;
ll dp[maxb][maxd];
ll dfs(int pos, int num, bool flag)
{
	if(pos == -1) return num == k;
	if(!flag && dp[pos][num] != -1) return dp[pos][num];
	ll ret = 0;
	int end = flag ? bit[pos] : 9;
	for(int i = 0; i <= end; ++i)
		ret += dfs(pos - 1, num + (i != 0), flag && (i == end));
	if(!flag) dp[pos][num] = ret;
	return ret;
}	
ll calc(string s)
{
	reverse(s.begin(), s.end());
	bit.clear();
	for(int i = 0; i < s.length(); ++i)
		bit.push_back(s[i] - '0');
	return dfs(bit.size() - 1, 0, 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	string L;
	cin >> L >> k;
	cout << calc(L) << endl;
	return  0;
}
		