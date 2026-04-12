#include<bits/stdc++.h>
#define int long long
using namespace std;
#define deb(x) cout<<#x<<" = "<<x<<"\n";
#define mod 1000000007


int dp[10001][103][2];
int d;
vector<int> num;

int ans(int idx, int sum, int flag)
{
	if(idx == (int) num.size())
		return sum % d == 0;
	
	if( dp[idx][sum][flag] != -1)
		return dp[idx][sum][flag];
	
	int res = 0;
	int lim = 9;
	if(flag == 0) lim = num[idx];
	
	for(int i=0; i<=lim; i++)
	{
		int new_flag = flag;
		
		if(i < lim && flag == 0) new_flag = 1;
		
		int temp = ans(idx+1, (sum+i) % d, new_flag);
		res = (res + temp) % mod;
	}
	
	return dp[idx][sum][flag] = res;
	
}

int solve(string s)
{
	
	for(int i=0; i<s.length(); i++)
		num.push_back(s[i] - '0');
	
	memset(dp, -1, sizeof(dp));
	int res = ans(0, 0, 0);
	return res;
}

signed main()
{
	string k; cin>>k;
	cin>>d;
	
	int res = solve(k);
	cout << (res - 1 + mod) % mod <<"\n";
}

