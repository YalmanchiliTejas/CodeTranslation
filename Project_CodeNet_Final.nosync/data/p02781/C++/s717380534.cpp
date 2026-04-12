#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 105;
ll dp0[MAX_N][4],dp1[MAX_N][4];

int main()
{
	string N;
	cin >> N;
	int L = N.size();
	int K;
	cin >> K;
	dp0[1][1] = N[0] - '0' - 1;
	rep(i,MAX_N)
	{
		dp0[i][0] = 1;
	}
	dp1[1][1] = 1;
	for(int i = 2; i <= L; ++i)
	{
		for (int j = 1; j <= 3; ++j)
		{
			dp0[i][j] = dp0[i-1][j-1]*9 + dp0[i-1][j] + dp1[i-1][j-1]*max(0,N[i-1]-'0'-1);
			if (N[i-1] != '0') dp0[i][j] += dp1[i-1][j];
			if (N[i-1] == '0') dp1[i][j] = dp1[i-1][j];
			else dp1[i][j] = dp1[i-1][j-1];
		}
	}

	/*
	for (int i = 1; i <= L; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			cout << dp0[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 1; i <= L; ++i)
	{
		for (int j = 0; j <= K; ++j)
		{
			cout << dp1[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << dp0[L][K] + dp1[L][K] << endl;
	return 0;
}