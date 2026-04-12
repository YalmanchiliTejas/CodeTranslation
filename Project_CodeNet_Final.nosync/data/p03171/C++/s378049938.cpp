#include<iostream>
#include<vector>
#include<algorithm>

int main(){
	int n;
	std::cin >> n;

	std::vector<int> a(n);
	for(int i=0; i<n; i++){
		std::cin >> a[i];
	}
	
	std::vector<std::vector<long long>> dp(n+1, std::vector<long long>(n+1));
	// d[i][j]: a[i, j)の区間で双方が最善を尽くした x-y
	for(int len=1; len<=n; len++){
		for(int i=0; i+len<=n; i++){
			int j = i+len;
			// 先手
			if((n-len)%2 == 0){
				dp[i][j] = std::max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
			}
			// 後手
			else{
				dp[i][j] = std::min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
			}
		}
	}

	std::cout << dp[0][n] << std::endl;
	return 0;

}