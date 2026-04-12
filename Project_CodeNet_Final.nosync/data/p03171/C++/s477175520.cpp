/*
*	User: Isanchez_Aguilar
*	Problem: AtCoder ABC134B - Golden Apple
*/
#include <bits/stdc++.h>

using namespace std;
using Long = long long;

const int MAX_N = 3001;

Long vals[MAX_N];
vector< vector<Long> > memo(MAX_N, vector<Long>(MAX_N, LONG_MIN));

Long dp(int i, int j)
{
	if (i == j)
		return vals[i];

	if (memo[i][j] == LONG_MIN)
	{
		memo[i][j] = max(vals[i] - dp(i + 1, j), vals[j] - dp(i, j - 1));
	}

	return memo[i][j];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	for (int i = 0;i < n; ++i)
		cin >> vals[i];


	cout << dp(0, n - 1);

	return 0;
}