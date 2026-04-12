#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1000000007
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	reverse(arr.begin(),arr.end());
	vector<int> dp(n+1,INF);
	dp[0] = -1;
	for(int i = 0; i < n; i++) {
		int index = upper_bound(dp.begin(),dp.end(),arr[i]) - dp.begin() - 1;
		//cout << "index:" << index << endl;
		dp[index+1] = arr[i];
		/*
		for(int j = 1; j < n+1; j++) {
			cout << dp[j] << " ";
		}
		cout << endl;
		*/
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += ((dp[i]!=INF)?1:0);
	}
	cout << ans << endl;
}
