
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using LL = long long;

int main(void)
{
	int r, g, b;
	cin >> r >> g >> b;
	if ((r * 100 + g * 10 + b) % 4)
	{
		cout << "NO" << endl;	
	}
	else
	{
		cout << "YES" << endl;
	}
	return 0;
}
