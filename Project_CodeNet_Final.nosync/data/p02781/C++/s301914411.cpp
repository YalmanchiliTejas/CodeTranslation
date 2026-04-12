#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define bug puts("--------------")
const int N = 1e5 + 10;
using namespace std;
int dp[120][120];
int a[120];	
int k;
int dfs(int pos,int sta,int lead,int limit){
	if(pos == -1) return sta == k;
	if(!lead&&!limit&&dp[pos][sta]!=-1) return dp[pos][sta];
	int up = limit?a[pos]:9;
	int tmp = 0;
	for(int i = 0;i <= up;++i){
		if(lead&&i == 0) tmp += dfs(pos - 1,sta,lead,limit&&i == a[pos]);
		else tmp += dfs(pos-1,sta + (i == 0?0:1),lead&&i == 0,limit&&i == a[pos]);
	}
	if(!limit&&!lead) dp[pos][sta] = tmp;
	return tmp;
}
int main(){
	string s;
	cin >> s;

	cin >> k;
	int l = s.size();
	int pos = 0;
	memset(dp,-1,sizeof dp);
	for(int i = l-1;i >= 0;-- i){
		a[pos++] = s[i] - '0';
	}
	cout<<dfs(pos-1,0,1,1);
}
