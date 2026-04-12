#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	string N;
	cin >> N;
	int n = N.size(); 
	int K;
	cin >> K;
	vector<vector<vector<ll>>> dp(n+1,vector<vector<ll>>(2,vector<ll>(4,0)));

	//dp[i][j][k]:=i桁目まで,(j=0は等しい,j=1は未満),k回取った場合の数(k=4は4つ以上取った場合)
	dp[0][0][0] = 1;
	for(int i = 0;i < n;i++){
		if(N[i] == '0'){
			for(int k = 0;k < 4;k++)dp[i+1][0][k] += dp[i][0][k];
			for(int k = 0;k < 4;k++)dp[i+1][1][k] += dp[i][1][k];
			for(int k = 0;k < 3;k++){
				dp[i+1][1][k+1] += dp[i][1][k] * 9;
			}
		}
		else{
			for(int k = 0;k < 3;k++)dp[i+1][0][k+1] += dp[i][0][k];
			for(int k = 0;k <= 3;k++){
				dp[i+1][1][k] += dp[i][0][k];//0を取ると0->1に遷移.
				dp[i+1][1][k] += dp[i][1][k];//1->1
			}
			for(int k = 0;k < 3;k++){
				dp[i+1][1][k+1] += dp[i][1][k] * 9;
			}
			for(int k = 0;k < 3;k++){
				dp[i+1][1][k+1] += dp[i][0][k] * (N[i] - '0' - 1);
			}
		}
	}
	cout << dp[n][0][K] + dp[n][1][K] << endl;
}
