#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int x[100], i, j = 0, n = 1, sum[100];
	while (1)
	{
		sum[j] = 0;
		cin >> n;
		if (n == 0)
			break;

		for (i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		for (i = 1; i < n - 1; i++)
		{
			sum[j] += x[i];
		}
		sum[j] = sum[j] / (n - 2);
		j++;
	}
	for (i = 0; i < j ; i++)
	{
		cout << sum[i] << endl;
	}
	return 0;

}
