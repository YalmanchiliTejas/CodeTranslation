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

	auto func = [&](bool flag)
	{
		deque<ll> q;
		auto left = 0;
		auto right = (int)A.size() - 1;
		if (flag)
		{
			q.push_back(A[left]);
			++left;
		}
		else
		{
			q.push_back(A[right]);
			--right;
		}

		flag = !flag;
		while (left <= right)
		{
			if (flag)
			{
				q.push_back(A[left]);
				++left;
				if (left <= right)
				{
					q.push_front(A[left]);
					++left;
				}
			}
			else
			{
				q.push_back(A[right]);
				--right;
				if (left <= right)
				{
					q.push_front(A[right]);
					--right;
				}
			}
			flag = !flag;
		}

		auto prev = q.front();
		q.pop_front();
		auto result = 0ll;
		while (!q.empty())
		{
			auto next = q.front();
			q.pop_front();
			result += abs(next - prev);
			prev = next;
		}

		return result;
	};

	auto res = func(true);
	res = max(res, func(false));

	cout << res << endl;

	return 0;
}