#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<vector>
#include<string>
#define int long long
using namespace std;

signed main() {
	int k, a, b; cin >> k >> a >> b;
	if (a >= k) { puts("1"); }
	else if (a <= b) {
		puts("-1");
	}
	else {
		int ans = (k - a) / (a - b);
		if ((k - a) % (a - b))ans++;
		cout << ans * 2 + 1 << endl;
	}
}