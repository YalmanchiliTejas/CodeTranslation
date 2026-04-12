#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define MAX INT_MAX
#define MIN INT_MIN
#define ss second
#define ff first
#define double long double
const int mod = 1e9+7;

int score(vector<int> &v){
	int n = v.size();
	int dp[n][n];
	for(int i = n-1; i >= 0; --i){
		for(int j = i; j < n; ++j){
			if(i == j)
				dp[i][j] = v[i];
			else {
				dp[i][j] = max(v[i]-dp[i+1][j], v[j]-dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int &a: v)
		cin >> a;
	cout << score(v) << endl;
	return 0;
}
