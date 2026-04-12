#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	vector<int> dp(N, INT_MAX);
	for (auto i = N - 1; i >= 0; --i)
	{
		auto it = upper_bound(dp.begin(), dp.end(), A[i]);
		*it = A[i];
	}

	auto ans = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (dp[i] >= INT_MAX)
		{
			break;
		}
		ans = i + 1;
	}

	cout << ans << endl;

	return 0;
}