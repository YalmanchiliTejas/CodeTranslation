#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define ll long long

int main(void){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++)
		cin >> v[i];
	// dp[i][j] - max value can get from array [i, j]
	vector<vector<ll> > dp(n, vector<ll>(n));
	for(int i = 0;i < n;i++){
		dp[i][i] = v[i];
	}
	for(int i = 1;i < n;i++){
		for(int j = i, k = 0;j < n;j++, k++){
			dp[k][j] = max(v[k]-dp[k+1][j], v[j]-dp[k][j-1]);
		}
	}
	cout << dp[0][n-1] << endl;
}