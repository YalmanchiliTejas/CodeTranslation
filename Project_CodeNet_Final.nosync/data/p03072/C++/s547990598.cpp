#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> H(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> H[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		bool view = true;
		for (int j = 1; j < i; j++)
		{
			if (H[j]>H[i])
			{
				view = false;
				break;
			}
		}
		if (view)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
