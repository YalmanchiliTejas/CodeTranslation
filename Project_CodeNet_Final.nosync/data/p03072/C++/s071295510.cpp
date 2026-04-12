#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))

int main()
{
	int n, counter = 1;
	cin >> n;
	vector<int> h(n);
	rep(i, 0, n - 1)
	{
		cin >> h[i];
	}
	rep(i, 1, n - 1)
	{
		bool isAble = true;
		rep(j, 0, i - 1)
		{
			if (h[i] < h[j]) isAble = false;
		}
		if (isAble) ++counter;
	}
	cout << counter << endl;
}