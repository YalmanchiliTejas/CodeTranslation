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
	ll N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	ll ans = 0;
	bool fl = true;
	while (fl) {
		fl = false;
		ll s = 0;
		vector<ll> p(N);
		for (int i = 0; i < N; i++) {
			p[i] = a[i] / N;
			s += p[i];
		}

		for (int i = 0; i < N; i++) {
			a[i] = a[i] - p[i] * N + (s - p[i]);
			if (a[i] >= N)fl = true;
		}
		ans += s;
	}

	cout << ans << endl;
}
