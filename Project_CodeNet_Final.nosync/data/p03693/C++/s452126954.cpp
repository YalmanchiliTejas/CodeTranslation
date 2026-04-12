#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int r, g, b, ans;
	cin >> r >> g >> b;
	ans = r * 100 + g * 10 + b;
	if (ans % 4 == 0) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}
