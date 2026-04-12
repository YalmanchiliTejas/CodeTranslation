#include <bits/stdc++.h>
#define _GLIACXX_DEAUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;

int		main(void)
{
	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(26));
	for (int i = 0; i < N; i++)
	{
		string S;
		cin >> S;
		for (int j = 0; S[j]; j++)
			A[i][S[j] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		int C = 1e9;
		for (int j = 0; j < N; j++)
			C = min(C, A[j][i]);
		for (int j = 0; j < C; j++)
			cout << (char)(i + 'a');
	}
	cout << endl;
}
