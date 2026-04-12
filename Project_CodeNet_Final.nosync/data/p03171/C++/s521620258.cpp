#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define inside sl<=l&&r<=sr
#define outside r<sl||sr<l
#define INF 1000000009
using namespace std;
typedef long long ll;

ll arr[3003];
int n;
ll dp[3003][3003];

int main(){
	//freopen("stl.gir", "r", stdin);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	
	for (int k = 1; k <= n; k++){
		for (int i = n-1; i >= 0; i--){
			if ((n-k)%2 == 0){
				// first player
				if (k == 1) dp[i][k] = arr[i];
				else if (i+k-1 < n) dp[i][k] = max(dp[i][k-1]+arr[i+k-1], dp[i+1][k-1]+arr[i]);
			} else {
				// second player
				if (k == 1) dp[i][k] = -arr[i];
				else if (i+k-1 < n) dp[i][k] = min(dp[i][k-1]-arr[i+k-1], dp[i+1][k-1]-arr[i]);
			}

		}
	}
	
	cout << dp[0][n] << endl;
	
}