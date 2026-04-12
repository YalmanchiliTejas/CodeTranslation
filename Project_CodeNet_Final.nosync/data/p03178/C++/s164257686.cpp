#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void add_self(int& a, int b)
{
	a+=b;
	if(a >= mod)
		a -= mod;
}
int main()
{
	string k;
	int d;
	cin>>k>>d;
	int len = k.size();
	vector<vector<int> > dp(d, vector<int>(2));
	dp[0][0] = 1;
	for(int where = 0; where< len; ++where)
	{
		vector<vector<int> > new_dp(d, vector<int>(2));
		for(int sum = 0; sum< d; ++sum){
			for(bool sm_already : {false, true}){
				for(int dig = 0; dig< 10; ++dig)
				{
					if(dig > k[where] - '0' && !sm_already)
						break;
						
					add_self(new_dp[(sum + dig) % d][sm_already || (dig < k[where] - '0')],dp[sum][sm_already]);
				}
			}
		}
		dp = new_dp;
	}
	int answer = (dp[0][false] + dp[0][true]) % mod;
	answer--;
	if(answer == -1)
		answer = mod - 1;
	cout<<answer<<endl; // -1 bidejki 0 se racuna kako resenie
	return 0;
}