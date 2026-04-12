#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> H(N);
	for (int i = 0; i < N; i++)
	{
		cin >> H[i];
	}

	int ans = 1;
	for (int i = 1; i < N; i++)
	{
		bool flag = true;
		for (int k = 0; k < i; k++)
		{
			if (H[i] < H[k])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}