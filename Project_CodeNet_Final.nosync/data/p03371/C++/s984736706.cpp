#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	auto ans = INT_MAX;
	for (auto i = 0; i <= max(X, Y); ++i)
	{
		auto temp = i * 2 * C;
		temp += A * max(0, X - i);
		temp += B * max(0, Y - i);
		ans = min(ans, temp);
	}

	cout << ans << endl;

	return 0;
}