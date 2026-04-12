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
	vector<ll> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	auto ans = 0ll;
	if (N % 2 == 0)
	{
		for (auto i = 0; i < N; ++i)
		{
			if (i < N / 2 - 1)
			{
				ans -= 2 * A[i];
			}
			else if (i == N / 2 - 1)
			{
				ans -= A[i];
			}
			else if (i == N / 2)
			{
				ans += A[i];
			}
			else
			{
				ans += 2 * A[i];
			}
		}
	}
	else
	{
		auto sum = 0ll;
		for (auto i = 0; i < N; ++i)
		{
			if (i < N / 2)
			{
				sum -= 2 * A[i];
			}
			else if (i < N / 2 + 2)
			{
				sum += A[i];
			}
			else
			{
				sum += 2 * A[i];
			}
		}
		ans = sum;
		sum = 0ll;
		for (auto i = 0; i < N; ++i)
		{
			if (i < N / 2 - 1)
			{
				sum -= 2 * A[i];
			}
			else if (i < N / 2 + 1)
			{
				sum -= A[i];
			}
			else
			{
				sum += 2 * A[i];
			}
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;

	return 0;
}