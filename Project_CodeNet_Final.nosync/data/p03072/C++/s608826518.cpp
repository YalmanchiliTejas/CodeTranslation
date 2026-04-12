#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> h(n);
	int max_height = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> h.at(i);
		if (max_height <= h.at(i))
		{
			count++;
		}
		max_height = max(max_height, h.at(i));
	}

	cout << count << endl;
}
