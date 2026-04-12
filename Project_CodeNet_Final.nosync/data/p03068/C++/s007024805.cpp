#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <complex>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <unordered_map>

using namespace std;
typedef long long ll;

int main()
{
	int n, k;
	string s;
	std::cin >> n;
	std::cin >> s;
	std::cin >> k;

	string s_k = s.substr(k - 1, 1);
	vector<int> v;

	for (int i = 0; i < s.size(); ++i)
	{
		if (s.substr(i, 1) != s_k) s.replace(i, 1, "*");
	}
	cout << s << endl;
}