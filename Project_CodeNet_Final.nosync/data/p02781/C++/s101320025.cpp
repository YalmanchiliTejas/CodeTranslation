#include <bits/stdc++.h> 
using namespace std; 

int dp[110][110][2]; 
vector<int> num;

int recur(int current_position, int count, int tight, int k) 
{ 
	if(count > k) {
		return 0;
	}
	
	if (current_position == num.size()) {
		return (count == k) ? 1 : 0;
	}

	if (dp[current_position][count][tight] != -1) 
		return dp[current_position][count][tight]; 

	int ans = 0; 

	int limit = (tight ? 9 : num[current_position]); 

	for (int dig = 0; dig <= limit; dig++) { 
		int currcount = count; 

		if (dig != 0) 
			currcount++; 

		int currTight = dig < num[current_position] ? 1 : tight; 

		ans += recur(current_position + 1, currcount, currTight, k); 
	}
	
	dp[current_position][count][tight] = ans; 
	return dp[current_position][count][tight];
} 

int main() 
{ 
	string x;
	cin >> x;
	int k;
	cin >> k;
	
	for(int i = 0; i < x.length(); i++) {
		num.push_back(x[i]-'0');
	}
	memset(dp, -1, sizeof(dp)); 
	cout << recur(0, 0, 0, k); 
	
	return 0; 
} 
