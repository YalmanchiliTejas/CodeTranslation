#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<int, map<long long, map<long long, long long>>> memo;

long long solve(int L, long long i, long long j)
{
	if (L == 0) {
		return 1;
	}
	if (memo.count(L) && memo[L].count(i) && memo[L][i].count(j)) {
		return memo[L][i][j];
	}
	long long ans = 0;
	long long len = (1LL << (L + 2)) - 3;
	//cout << "level " << L << ": " << len << "(" << i << "," << j << ")" << endl;

	if (i < len / 2) {
		if (j < 1) {

		}
		else if (j < len / 2) {
			ans += solve(L - 1, 0, j - 1);
		}
		else if (j > len / 2) {
			ans += solve(L - 1, 0, len / 2 - 1);
			ans += 1;
			ans += solve(L - 1, 0, j - len / 2 - 1);
		}
		else {
			ans += 1;
			ans += solve(L - 1, 0, j - 1);
		}
	}
	else if (i > len / 2) {
		ans += solve(L - 1, i - len / 2 - 1, j - len / 2 - 1);
	}
	else {
		if (i < j) {
			ans += solve(L - 1, 0, j - i - 1);
		}
	}
	return memo[L][i][j] = ans;
}

int main()
{
	int N;
	long long X;
	cin >> N >> X;

	memo.clear();
	long long ans = solve(N, 0, X - 1);
	cout << ans << endl;
}
