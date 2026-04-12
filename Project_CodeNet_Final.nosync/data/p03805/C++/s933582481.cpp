//順列全探索
#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;


int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>>connected(N, vector<int>(N));
	int a, b;
	for (size_t i = 0; i < M; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		connected.at(a).at(b) = 1;
		connected.at(b).at(a) = 1;
	}
	vector<int>perm(N);
	for (size_t i = 0; i < N; i++)
	{
		perm.at(i) = i;
	}
	int ans = 0;
	bool chk = true;
	do
	{
		chk = true;
		if (perm.at(0) != 0)break;
		for (size_t i = 0; i < N-1; i++)
		{
			if (connected.at(perm.at(i)).at(perm.at(i+1)) == 0)chk = false;
		}
		if (chk)ans++;
	} while (next_permutation(perm.begin(),perm.end()));
	cout << ans;
}
