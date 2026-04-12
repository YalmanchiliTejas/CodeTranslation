#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const ll LLINF = 1e18;

ll dp[200001][2][4];

int main(){
	int n;
	cin >> n;
	vector<ll> a(n+1);
	for (int i = 0; i <= 200000; i++){
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 4; k++){
				dp[i][j][k] = -LLINF;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	dp[1][0][0] = a[1];
	dp[1][1][1] = 0;
	for (int i = 2; i <= n; i++){
		for (int j = 0; j < 2; j++){
			for (int k = 0; k < 3; k++){
				if (dp[i-1][j][k] != -LLINF){
					if (j == 0){
						dp[i][1][k] = max(dp[i][1][k], dp[i-1][j][k]);
					}else{
						dp[i][0][k] = max(dp[i][0][k], dp[i-1][j][k] + a[i]);
						dp[i][1][k+1] = max(dp[i][1][k+1], dp[i-1][j][k]);
					}
				}
			}
		}
	}
	if (n%2) cout << max(dp[n][0][2], dp[n][1][1]) << endl;
	else cout << max(dp[n][0][1], dp[n][1][0]) << endl;
	
	return 0;
}

