#include <iostream>

int main()
{
	using namespace std;

	int n;
	cin >> n;

	int max = 0;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;

		if (h >= max)
		{
			result++;
			max = h;
		}
	}

	cout << result << endl;
}