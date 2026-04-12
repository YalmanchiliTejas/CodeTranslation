#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	vector<ll> a(N + 1), sums(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		sums[i] = (sums[i - 1] + a[i]) % DIV;
	}

	ll ans = 0;
	for (int j = 1; j <= N; j++) {
		ans += (a[j] * sums[j - 1]) % DIV;
		ans %= DIV;
	}
	cout << ans << endl;
}
