#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
int main()
{
	long N, S;
	cin >> N >> S;
	long waru = 998244353;
	vector<long> dp(S + 1);//パターン、初期値を掛ける
	vector<long> pure(S + 1), filled(S+1);//初期値とそこに紐づくパターン数
	vector<long> A(N);
	for (long& a : A) {
		cin >> a;
	}
	long count = 0;
	for (int i = 0; i < N; i++)
	{
		pure = vector<long>(S + 1);
		for (int k = S + 1 - A[i]-1; k >=0 ; k--)
		{
			if (k + A[i] == S) {
				count =(count+ dp[k] * (N - i) )% waru;
				/*for (int m = 0; m < dp[k].size(); m++)
				{
					count += (dp[k][m] + 1) * (N - i) % waru;
					//break;
				}*/
			}
			else if (pure[k] == 0 && filled[k]==1) {
				dp[k + A[i]] = (dp[k + A[i]] + dp[k])%waru;//.insert(dp[k + A[i]].end(), dp[k].begin(), dp[k].end());
				pure[k + A[i]] = 1;
				filled[k+A[i]] = 1;
			}


		}
		if (A[i] < S) {
			dp[A[i]]+=i+1;
			filled[A[i]] = 1;
		}
		if (A[i] == S)
		{
			count =(count+ (N - i) * (i + 1)) % waru;
		}

	}
	cout << count;
	return 0;
}