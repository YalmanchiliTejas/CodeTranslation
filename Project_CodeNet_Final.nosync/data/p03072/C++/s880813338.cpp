#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[100], ji = 0;
	while (n--)
	{
		cin >> a[ji++];
	}
	int sum = 1;
	int max=a[0];
		for (int j = 1; j < ji; j++)
		{
			if (a[j] >= max)
			{
				sum++;
				max = a[j];
			}
		}
	
	cout << sum << endl;
}