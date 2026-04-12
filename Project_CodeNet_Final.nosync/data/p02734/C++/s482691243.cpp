#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;

constexpr ll mod=998244353;

ll dp[3030][6030][3];

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n,s; cin >> n >> s;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=s;j++){
			(dp[i+1][j][0]+=dp[i][j][0])%=mod;
			(dp[i+1][j][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
			(dp[i+1][j][2]+=dp[i][j][0]+dp[i][j][1]+dp[i][j][2])%=mod;
			(dp[i+1][j+a[i]][1]+=dp[i][j][0]+dp[i][j][1])%=mod;
			(dp[i+1][j+a[i]][2]+=dp[i][j][0]+dp[i][j][1])%=mod;
		}
	}
	cout << dp[n][s][2] << endl;
}