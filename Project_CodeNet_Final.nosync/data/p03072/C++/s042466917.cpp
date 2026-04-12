#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <math.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> H(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> H[i];
	}

	int ret = 1;
	for (int i = 1; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (H[i] < H[j])
				break;

			if (j == i - 1)
			{
				++ret;
				break;
			}
		}
	}

	cout << ret << endl;

	return 0;
}