#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n; 
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int ans = 1;
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= max)
		{
			max = arr[i];
			ans++;
		}
	}

	cout << ans << endl;
}
