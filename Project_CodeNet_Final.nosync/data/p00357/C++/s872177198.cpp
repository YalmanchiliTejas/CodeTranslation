#include <iostream>
#include <algorithm>
using namespace std;

int n;
int d[300000];

bool solve()
{
	int reachablePoint = 0;
	for (int i = 0; i < n; i++)
	{
		if (i > reachablePoint) return false;
		reachablePoint = max(reachablePoint, d[i] + i);
	}

	reverse(d, d + n);

	reachablePoint = 0;
	for (int i = 0; i < n; i++)
	{
		if (i > reachablePoint) return false;
		reachablePoint = max(reachablePoint, d[i] + i);
	}

	return true;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int distance;
		cin >> distance;
		d[i] = distance / 10;
	}
	if (solve()) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}