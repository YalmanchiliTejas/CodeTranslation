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
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> H(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> H[i];
	}

	auto maxH = H[0];
	auto count = 1;

	for (auto i = 1; i < N; ++i)
	{
		if (H[i] >= maxH)
		{
			++count;
		}

		maxH = max(maxH, H[i]);
	}

	cout << count << endl;

	return 0;
}
