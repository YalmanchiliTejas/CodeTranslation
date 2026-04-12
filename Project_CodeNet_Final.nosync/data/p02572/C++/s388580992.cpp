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
#include <complex>

using namespace std;

//#pragma GCC optimize("Ofast")
//#pragma GCC optimization("unroll-loops, no-stack-protector")
//#pragma GCC target("avx,avx2,fma")


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, s, MOD = 1000000007, ans = 0;
	cin >> n;
	vector<long long> a(n);
	s = 0;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		ans = (ans + s * a[i]) % MOD;
		s = (s + a[i]) % MOD;
	}
	cout << ans << "\n";


	return 0;
}

