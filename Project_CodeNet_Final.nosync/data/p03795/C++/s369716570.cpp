#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int ans = n*800 - n/15*200;
	
	cout << ans << "\n";

	return 0;
}
