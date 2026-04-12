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
	int n, k, i, j;
	cin >> n >> s >> k;
	for (i = 0; i < n; i++) {
		if (s[i] != s[k - 1]) s[i] = '*';
	}
	cout << s << "\n";

	return 0;
}

