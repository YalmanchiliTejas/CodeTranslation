#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	cin >> n;
	long long ans = 800LL*n - 200LL*(n/15);
	cout << ans << endl;

	return 0;
}