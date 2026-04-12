#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MOD	1000000007
#define int	long long
#define pii pair<int,int> 
#define vi vector<int>
using namespace std;

int dp[105][4][2];

string s;
int n;

int solve(int pos, int left, int flag){
	if(left < 0)
		return 0;
	if(pos == n){
		return left == 0;
	}
	if(dp[pos][left][flag] != -1)
		return dp[pos][left][flag];
	int ans = 0;
	ans = solve(pos+1,left,(flag | (s[pos]-'0')) > 0);
	int max_digit = s[pos] - '0';
	if(flag)
		max_digit = 9;
		
	for(int i = 1; i <= max_digit; i++){
		if(i == max_digit){
			ans += solve(pos+1,left-1,flag);
		}
		else
			ans += solve(pos+1,left-1,1);
	}
	//cout << "dp[" << pos << "][" << left << "][" << flag << "] = " << ans << endl;
	return dp[pos][left][flag] = ans;
}

int getAns(int k){
	memset(dp,-1,sizeof dp);
	return solve(0,k,0);
}

int32_t main(){
	cin >> s;
	int k;
	cin >> k;
	n = s.size();
	
	if(n < k){
		cout << 0;
		return 0;
	}
	
	//if(n < 7){
		//int no = stoi(s);
		//int ans = 0;
		//for(int i = 1; i <= no; i++){
			//string p = to_string(i);
			//int cnt = 0;
			//for(auto x : p)
				//if(x != '0')
					//cnt++;
			//if(cnt == k)
				//ans++;
		//}
		//cout << ans << endl;
		//return 0;
	//}
	cout << getAns(k) << endl;
	
	
	return 0;
}

