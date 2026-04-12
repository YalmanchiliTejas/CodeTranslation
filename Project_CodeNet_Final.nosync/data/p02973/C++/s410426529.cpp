#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<long long> A(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	vector<long long> list;
	list.push_back(A[0]);
	for (auto i = 1; i < N; ++i)
	{
		auto temp = A[i];
		auto low = 0;
		auto high = (int)list.size() - 1;
		while (high >= low)
		{
			auto mid = (high + low) / 2;
			if (list[mid] < temp)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		if (low >= list.size())
		{
			list.push_back(temp);
		}
		else
		{
			list[low] = temp;
		}
	}

	cout << list.size() << endl;

	return 0;
}