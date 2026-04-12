#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int h[20];
	for (int i = 0; i < n; ++i)
	{
		cin >> h[i];
	}
	int ans = 0;
	int nowMax = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
		{
			ans += 1;
			nowMax = h[i];
		}
		else
		{
			if (h[i] >= nowMax)
			{
				ans += 1;
				nowMax = max(nowMax,h[i]);
			}
		}
	}
	cout << ans;
	return 0;
}