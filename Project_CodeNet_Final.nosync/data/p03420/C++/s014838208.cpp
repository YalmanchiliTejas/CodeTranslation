#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main() {
	ll N, K;
	cin >> N >> K;

	ll ans = 0;
	if (K == 0) ans = N * N;
	else {
		for (ll b = K + 1; b <= N; b++) {
			ll q = (N - (b - 1)) / b;

			ans += (q + 1) * (b - 1 - (K - 1));
			if (N - (q + 1) * b - (K - 1) > 0)
				ans += N - (q + 1) * b - (K - 1);
		}
	}
	cout << ans << endl;
}