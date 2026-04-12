#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int lld;

const lld mod = 1e9+7;
const lld INF = 1e9;
//const lld MAXN = 1e9;

int main()
{
	int n;
	vector<int> a;

	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	vector<int> sol(n);

	if (n % 2 == 0)
	{
		int k = n / 2;
		int j = 0;

		for(int i = k; i < n; i++)
		{
			sol[i] = a[j];
			j += 2;
		}

		j = 1;
		for(int i = k-1; i >= 0; i--)
		{
			sol[i] = a[j];
			j += 2;
		}

	}else
	{
		int k = n / 2;
		int j = 1;

		for(int i = k+1; i < n; i++)
		{
			sol[i] = a[j];
			j += 2;
		}

		j = 0;
		for(int i = k; i >= 0; i--)
		{
			sol[i] = a[j];
			j += 2;
		}
	}


	for(int i = 0; i < n; i++)
	{
		cout << sol[i] << " ";
	}
	cout << endl;

	return 0;
}