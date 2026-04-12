#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> h;
	int max = 0;
	int total = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		h.push_back(num);
		if (max <= num)
		{
			max = num;
			++total;
		}
	}

	cout << total;

	return 0;
}