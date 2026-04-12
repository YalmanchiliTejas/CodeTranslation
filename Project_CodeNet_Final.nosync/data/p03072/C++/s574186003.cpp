#include <iostream>
using namespace std;

int main()
{
	bool see = true;
	int n, a[21], cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		see = true;
		for (int j = 0; j < i; j++)
		{
			if (a[j] > a[i])
			{
				see = false;
				break;
			}
		}
		if (see)
			cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}