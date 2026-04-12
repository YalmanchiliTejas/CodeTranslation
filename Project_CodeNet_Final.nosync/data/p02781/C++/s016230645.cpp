#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string N;
int K;

ll dp[150][2][5];

void solve()
{
	dp[0][0][0]=1;
	const int n = N.length();
	for(int i=0;i<n;++i)for(int smaller=0;smaller<2;++smaller)for(int num=0;num<=K;++num){
		for(int k=0;k<=(smaller?9:N[i]-'0');++k){
			if(k == 0) dp[i+1][smaller|(k<N[i]-'0')][num] += dp[i][smaller][num];
			else{
				if(num < K) dp[i+1][smaller|(k<N[i]-'0')][num+1] += dp[i][smaller][num];
			}
		}
	}
	ll ans = dp[n][0][K]+dp[n][1][K];
	cout << ans << '\n';
}

int main()
{
	cin >> N;
	cin >> K;
	solve();
	return 0;
}