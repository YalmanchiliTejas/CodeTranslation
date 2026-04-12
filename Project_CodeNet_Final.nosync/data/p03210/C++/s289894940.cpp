#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const long long INF = 1e9 + 7;
using namespace std;
typedef long long ll;
map<int, int> mp;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x;
	cin >> x;
	if (x == 7 || x == 5 || x == 3) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}