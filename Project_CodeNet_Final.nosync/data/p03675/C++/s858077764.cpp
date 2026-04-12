#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll inf = (ll)1e9;
const ll mod = (ll)1e9 + 7;

int main()
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a.at(i);
	}

	deque<int> b;
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
		{
			b.push_front(a.at(i));
		}
		else
		{
			b.push_back(a.at(i));
		}
	}

	if (n % 2 == 0)
	{
		reverse(b.begin(), b.end());
	}

	for (int i = 0; i < n; i++)
	{
		cout << (i == 0 ? "" : " ") << b.at(i);
	}

	cout << endl;
}
