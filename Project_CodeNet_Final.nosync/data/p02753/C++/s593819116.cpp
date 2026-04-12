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

	string s;
	cin >> s;

	bool ans = false;
	if ((s[0] != s[1]) || (s[1] != s[2]) || (s[0] != s[2])) ans = true;
	if (ans) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
