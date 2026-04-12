#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
int a[5005];
int nx[5005][5005];
int dp[5005][5005];
unordered_map<int, int> mp;

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	
	if(n <= 2){
		cout << n << endl;
		return 0;
	}
	
	for(int i = 1; i <= n; i++) mp[a[i]] = i;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(j >= i) continue;
			if(mp.count(a[i] + a[i]-a[j])) nx[i][j] = mp[a[i]+a[i]-a[j]];
		}
	}
	
	for(int i = 2; i <= n; i++){
		for(int j = 1; j < i; j++){
			if(nx[i][j]) dp[nx[i][j]][i] = dp[i][j] + 1;
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < i; j++){
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans+2 << endl;
	return 0;
}
