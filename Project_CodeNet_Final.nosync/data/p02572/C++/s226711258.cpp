#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stdlib.h>
#include <map>
#include <cmath>
#define MOD_P 1000000007
#define MOD_Q 998244353
#define PI 3.14159265358979
#define ll long long
using namespace std;

ll mmul(int x, int y)
{
	ll m = (ll)x * (ll)y;
	m %= MOD_P;
	return m;
}



int main()
{
	int n;
	cin >> n;
	ll ans = 0LL;
	queue<int>que;
	ll sum = 0LL;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sum += (ll)tmp;
		sum %= MOD_P;
		que.push(tmp);

	}

	while (!que.empty()) {
		int x = que.front();
		que.pop();
		sum -= (ll)x;
		//printf("%d * %lld = %lld->%lld\n", x, sum, (ll)x * sum, ((ll)x * sum) % MOD_P);
		if (sum < 0) {
			sum += MOD_P;
		}
		ans += mmul(x, sum);
		ans %= MOD_P;
	}

	printf("%lld", ans);

	return 0;
}
