#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n, h, ht;
	int cnt = 1;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			cin >> h;
			v.push_back(h);
			continue;
		}
		cin >> ht;
		v.push_back(ht);
	}
	int j, max = 0;
	for (int i = 1; i < n; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (v[j] > max)max = v[j];
		}
		if (max <= v[i] && v[0] <= v[i])cnt++;
	}
	cout << cnt << endl;
}