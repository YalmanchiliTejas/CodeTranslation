#include <bits/stdc++.h>
using namespace std;

#define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int memo[200010][5][2];
int a[200010];

int dp(int i, int cnt, int num){
	if(num == 0) return 0;
	if(memo[i][cnt][num == 0] != LLONG_MIN) return memo[i][cnt][num == 0];

	int ans = dp(i+2, cnt, num-1) + a[i];
	if(cnt > 0){
		ans = max(ans, dp(i+1, cnt-1, num));
	}

	return memo[i][cnt][num == 0] = ans;
}

signed main(){
	int n;
	cin >> n;

	for(int i = 0;i < n;i++) cin >> a[i];

	for(int i = 0;i < 200010;i++){
		for(int j = 0;j < 5;j++){
			memo[i][j][0] = memo[i][j][1] = LLONG_MIN;
		}
	}

	if(n % 2 == 0){
		cout << dp(0, 1, n/2) << endl;
	}else{
		cout << dp(0, 2, n/2) << endl;
	}

	return 0;
}
