#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[21], n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mins = a[0], sum = 1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] >= mins)
		{
			sum++;
			mins = a[i];
		}
	}
	cout << sum;
	return 0;
}