

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <array>
#include <map>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>
#include <ctgmath>
#include <set>
#include <queue>
#include <fstream>
#include <ostream>
#include <random>
#include <chrono>
using namespace std;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	string s;
	int k;
	cin >> n >> s >> k;

	k--;
	char c = s[k];

	for (auto i : s)
	{
		if (i != c)
		{
			cout << '*';
		}
		else
		{
			cout << i;
		}
	}
	cout << "\n";
}