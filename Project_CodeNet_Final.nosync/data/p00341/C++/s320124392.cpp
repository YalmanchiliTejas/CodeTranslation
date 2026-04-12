#include <iostream>
#include <algorithm>
using namespace std;

int a[12];
bool canMakeRectangle()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (a[i * 4 + j] != a[i * 4 + j + 1]) return false;
		}
	}
	return true;
}

int main()
{
	for (int i = 0; i < 12; i++) cin >> a[i];
	sort(begin(a), end(a));
	if (canMakeRectangle()) cout << "yes" << endl;
	else cout << "no" << endl;

	return 0;
}