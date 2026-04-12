#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main ()
{
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #define int ll
	
	int n;
	cin >> n;
	vector <int> nums(n+1, 0);
	
	for (int i=1; i<=n; i++) cin >> nums[i];

	vector <vector <int> > dp(n+1, vector <int> (n+1, 0));
	
	for (int left = n; left >= 1; left--){
		for (int right = 1; right <= n; right++){
			if (right < left) continue;
			if (left == right){
				dp[left][left] = nums[left];
				continue;
			}

			dp[left][right] = max(-dp[left][right-1] + nums[right], nums[left] - dp[left+1][right]);
		}
	}

	cout << dp[1][n] << endl;

	return 0;
	
}