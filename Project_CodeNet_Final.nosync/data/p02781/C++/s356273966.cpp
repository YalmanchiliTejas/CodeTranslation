#include <bits/stdc++.h> 
#define int long long
#define deb(x) cout<<#x <<" = "<<x<<"\n";
using namespace std; 
int k;
string s;
int n;
int dp[110][10][3];
int solve(int idx, int non_zero, int flag)
{
	if(non_zero > k)
		return 0;
	if(idx >=n )
		return non_zero == k;
	if(dp[idx][non_zero][flag] != -1)
		return dp[idx][non_zero][flag];
	
	int res = 0;
	int lim = 9;
	if(flag == 0) lim = s[idx] - '0';
	for(int i=0; i<=lim; i++)
	{
		int new_flag = flag;
		int new_non_zero = non_zero;
		if(flag == 0 && i<lim) new_flag = 1;
		if(i>0) new_non_zero++;
		res += solve(idx+1, new_non_zero, new_flag);
	}
	dp[idx][non_zero][flag] = res;
	return res;
}
signed main() 
{
	cin>>s;
	cin>>k;
	n = s.length();
	memset(dp, -1, sizeof(dp));
	cout<< solve(0, 0, 0) <<"\n";
	
}