#include <bits/stdc++.h>
using namespace std;

int		main(void)
{
	int N;

	cin >> N;
	int high = 0;
	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		int H;

		cin >> H;
		if (H >= high)
		{
			high = H;
			ans++;
		}
	}
	cout << ans << endl;
}
