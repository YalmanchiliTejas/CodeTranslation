#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void solve(string N, long long K){
	vector<vector<vector<int>>> dp(N.size()+1, vector<vector<int>>(2, vector<int>(4, -1)));
	function<int(int, int, int)> f = [&](int i, int j, int k) -> int{
		if(k > 3){
			return 0;
		}
		if(i == N.size())return k == K;

		if(dp[i][j][k] != -1)return dp[i][j][k];
		int NN = N[i] - '0';
		int ma;
		if(j)ma = N[i] - '0';
		else ma = 9;
		dp[i][j][k] = 0;
		for(int l = 0;l <= ma;l++){
			dp[i][j][k] += f(i + 1, j && l == ma,k + (l == 0 ? 0 : 1));
		}
		return dp[i][j][k];
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
