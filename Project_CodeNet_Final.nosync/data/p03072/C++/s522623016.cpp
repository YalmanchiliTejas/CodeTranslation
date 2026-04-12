#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <fstream>
#include <cstring>

using namespace std;

int arr[21];
vector <int> v;
int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n, t;

	arr[0] = 0;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t;
		arr[i + 1] = max(arr[i], t);
		v.push_back(t);
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= v[i])
		{
			res++;
		}
	}

	cout << res << '\n';

	return 0;
}
