#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct iostream_init_struct
{ 
	iostream_init_struct()
	{
		std::cin.tie(0);
		std::cin.sync_with_stdio(false);
	}
} iostream_init;

int main(void)
{
	int N;
	vector<pair<int, int>> list;

	cin >> N;
	list.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		if (x < y)
		{
			list.emplace_back(x, y);
		}
		else
		{
			list.emplace_back(y, x);
		}
	}

	// case R_max = max, B_min = min:
	//      R <- bigger, B <- smaller
	int R_max = INT_MIN;
	int R_min = INT_MAX;
	int B_max = INT_MIN;
	int B_min = INT_MAX;
	for (int i = 0; i < N; ++i)
	{
		int bigger = list[i].second;
		int smaller = list[i].first;
		R_max = max(R_max, bigger);
		R_min = min(R_min, bigger);
		B_max = max(B_max, smaller);
		B_min = min(B_min, smaller);
	}

	long long result = (long long)(R_max - R_min) * (long long)(B_max - B_min);

	int max_of_all = R_max;
	int min_of_all = B_min;

	// case B_max = max, B_min = min:
	//      minimize R_max - R_min
	sort(begin(list), end(list));
	R_max = list[list.size() - 1].first;
	R_min = INT_MAX;
	int R_range = R_max - list[0].first;
	for (int i = 0; i < N - 1; ++i)
	{
		R_max = max(R_max, list[i].second);
		R_min = min(R_min, list[i].second);
		if (R_min <= list[i + 1].first)
		{
			R_range = min(R_range, R_max - R_min);
			break;
		}
		else
		{
			R_range = min(R_range, R_max - list[i + 1].first);
		}
		
	}

	result = min(result, (long long)(R_range) * (long long)(max_of_all - min_of_all));

	cout << result << endl;
}