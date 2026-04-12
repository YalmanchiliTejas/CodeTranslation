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

#define MOD 1000000007
#define INIT -1

int main() {
	int n, k;
	cin >> n >> k;
	long long int ans = 0;
	for (int b = k + 1; b <= n; b++) {
		ans += n / b * (b - k);
		ans += max(0, n - (n / b) * b - k + 1);
		if (k == 0) ans--;
		// cout << ans << endl;
	}
	cout << ans << endl;
}