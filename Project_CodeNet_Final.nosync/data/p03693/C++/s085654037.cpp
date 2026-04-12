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
	int a[3];
	cin >> a[0] >> a[1] >> a[2];

	

	int x = 10*a[1] + a[2];

	if (x % 4== 0)
	{
		cout << "YES" << endl;
	}else
	{
		cout << "NO" << endl;

	}

	return 0;
}