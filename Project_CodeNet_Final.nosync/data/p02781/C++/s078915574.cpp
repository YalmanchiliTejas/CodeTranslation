#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve(string N, long long K){
	vector<vector<vector<int>>> dp(N.size()+1, vector<vector<int>>(2, vector<int>(4, -1)));
	function<int(int, int, int)> f = [&](int i, int tight, int sum) -> int{
		if(sum > 3)return 0;

		if(i == N.size())return sum == K;

		if(dp[i][tight][sum] != -1)return dp[i][tight][sum];
		dp[i][tight][sum] = 0;
		int num = N[i] - '0';

		int ma;
		if(tight){
			ma = num;
		}else{
			ma = 9;
		}
		for(int j = 0;j <= ma;j++){
			dp[i][tight][sum] += f(i + 1, tight && j == ma, sum + (j == 0 ? 0 : 1));
		}
		return dp[i][tight][sum];
	};
	cout<<f(0, 1, 0)<<endl;
}

int main(){
    string N;
    cin >> N;
    long long K;
    scanf("%lld",&K);

    solve(N, K);
    return 0;
}
