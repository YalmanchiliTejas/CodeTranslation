#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int n;
long long int a[200000];
map<pair<int, int>, long long int> res;

long long int solve(int i, int rest) {
	if ((n - i + 1) / 2 + (n - i + 1) % 2 < rest)
		return (long long int)-mod * 200000;
	if (rest == 0) return 0;
	// cout << i << " " << rest << endl;
	if (res.find(make_pair(i, rest)) != res.end())
		return res[make_pair(i, rest)];
	long long int ans = a[i] + solve(i + 2, rest - 1);
	if ((n - i) / 2 + (n - i) % 2 >= rest) ans = max(ans, solve(i + 1, rest));
	return res[make_pair(i, rest)] = ans;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << solve(0, n / 2) << endl;
}