#include <iostream>
using namespace std;

int main()
{
	int n, h[20];
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> h[i];
	int ans = 1;
	int max = h[0];
	for (int i = 1; i < n; i ++)
	{
		if (h[i] >= max)
		{
			ans ++;
			max = h[i];
		}
	}
	cout << ans << endl;
}