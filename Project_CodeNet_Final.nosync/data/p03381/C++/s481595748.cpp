#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define FOR(i, a, b) for(decltype(b) i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> x(n);
	for (auto& i : x)
		cin >> i;
	
	auto y = x;
	sort(y.begin(), y.end());

	for (const auto& i : x)
		cout << (i > y[n / 2 - 1] ? y[n / 2 - 1] : y[n / 2]) << endl;

	return 0;
}
