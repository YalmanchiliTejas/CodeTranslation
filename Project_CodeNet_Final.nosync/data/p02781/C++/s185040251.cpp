#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int dp[110][5];

string s;
int k, n;
ll dfs(int pos, int num, bool lim){
	if(num>k)return 0;
	if(pos>=n) return num==k;
	if(!lim&&dp[pos][num]!=-1)return dp[pos][num];
	ll ret = 0;
	int up = lim?s[pos]-'0':9;
	for(int i=0; i<=up; ++i){
		ret += dfs(pos+1, num+(i!=0), lim&&(i==up)); 
	} 
	if(!lim)dp[pos][num]=ret;
	return ret;
}
int main()
{
	cin >> s >> k;
	memset(dp, -1, sizeof(dp));
	n=s.size();
	cout << dfs(0, 0, 1)<<"\n";
} 