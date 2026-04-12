#define pb push_back
#define mp make_pair
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2000000 + 100;
ll arr[N], dp[6001][6001], ans = 0;
int n;
void solve(){
	cin >> n; 
	ans = 2;
	for(int i = 0; i < n; i++) cin >> arr[i], dp[i][n - 1] = 2;
	sort(arr, arr + n);
	for(int j = n - 2; j >= 1; j--){
		int i = j - 1, k = j + 1;
		while(i >= 0 && k <= n - 1){
			if(arr[i] + arr[k] < 2 * arr[j]){
				k++;
			}else if(arr[i] + arr[k] > 2 * arr[j]){
				dp[i--][j] = 2;
			}else{
				dp[i][j] = dp[j][k] + 1;
				ans = max(ans, dp[i][j]);
				i--; k++;
			}
		}
		while(i >= 0){
			dp[i][j] = 2;
			i--;
		}
	}
	cout << ans << endl;
}
int main(){
	int t = 1; 
	while(t--) solve();
	return 0;
}
