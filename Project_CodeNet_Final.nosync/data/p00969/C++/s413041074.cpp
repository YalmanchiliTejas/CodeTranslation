#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	vector<vector<int>> dp(n);
	vector<vector<int>> dis(n);
	vector<int> pos(n);
	int res = 0;
	for(int i = 0;i < n;i++){
		for(int j = i - 1;j >= 0;j--){
			while(pos[j] < (int)dp[j].size() && dis[j][pos[j]] < v[i] - v[j]) ++pos[j];
			if(pos[j] < (int)dp[j].size() && dis[j][pos[j]] == v[i] - v[j]){
				dp[i].push_back(dp[j][pos[j]] + 1);
			}
			else{
				dp[i].push_back(2);
			}
			res = max(res, dp[i].back());
			dis[i].push_back(v[i] - v[j]);
		}
	}
	cout << res << endl;
	return 0;
}


