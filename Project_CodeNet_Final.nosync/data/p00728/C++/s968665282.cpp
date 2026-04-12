#include <iostream>
using namespace std;

int main()
{
	int n;
	for (; cin >> n, n != 0;)
	{
		int sum = 0;
		int max = -1;
		int min = 1001;
		int s[100];
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			max = (max < s[i]) ? s[i] : max;
			min = (min > s[i]) ? s[i] : min;
			sum += s[i];
		}
		cout << (sum - (max + min)) / (n - 2) << endl;
	}
	return 0;
}