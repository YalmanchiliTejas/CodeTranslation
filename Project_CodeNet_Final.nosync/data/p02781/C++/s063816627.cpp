#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
int dp[200][200][2];
vector <int> num;
int k;
string s;
int solve(int pos, int cnt, int flag)
{
	if(cnt > k) return 0;
	if(pos == s.size())
	{
		if(cnt == k) return 1;
		else return 0;
	}
	if(dp[pos][cnt][flag] != -1) return dp[pos][cnt][flag];
	int res = 0;
	int limit;
	if(flag == 0) limit = s[pos]-'0';
	else limit = 9;
	for(int digit = 0; digit <= limit; digit++)
	{
		int nf = flag;
		int ncnt = cnt;
		if(digit != 0) ncnt++;
		if(flag == 0 && digit < limit) nf = 1;
		if(ncnt <= k) res += solve(pos+1,ncnt,nf);
	}
	return dp[pos][cnt][flag] = res;
}
int solve1(string s)
{
	memset(dp,-1,sizeof(dp));
	int result = solve(0,0,0);
	return result;
}
int32_t main()
{
	cin >> s >> k;
	cout << solve1(s) << "\n";
	return 0;
}