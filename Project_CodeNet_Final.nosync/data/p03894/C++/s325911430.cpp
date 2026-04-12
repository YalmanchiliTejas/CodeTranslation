#include <iostream>

using namespace std;

int uz[100005];

int main()
{
	int n, q, x, y;

	cin >> n >> q;
	uz[1] = 1;
	int poz1 = 1;
	for (int i = 1; i <= q; i++)
	{
		uz[poz1 - 1] = uz[poz1 + 1] = 2;
		cin >> x >> y;
		swap(uz[x], uz[y]);
		if (uz[x] == 1)
			poz1 = x;
		else if (uz[y] == 1)
			poz1 = y;
	}
	uz[poz1 - 1] = uz[poz1 + 1] = 2;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (uz[i] != 0);
	cout << ans << '\n';
	return 0;
}