#include <iostream>
using namespace std;

int h[100];

int main()
{
	int n;
	cin >> n;
	int max = h[1];
	int a = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> h[i];
		if (h[i] >= max)
		{
			a = a + 1;
			max = h[i];
		}
	}
	cout << a;
}