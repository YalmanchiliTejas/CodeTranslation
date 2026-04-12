#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;



int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int x, y;
	cin >> x >> y;
	
	c *= 2;
	int ans = c*max(x,y);
	for (int i = max(x, y); i >= 0; i--) {
		int t;
		t = i * c + max(0, x - i)*a + max(0, y - i)*b;
		ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}
