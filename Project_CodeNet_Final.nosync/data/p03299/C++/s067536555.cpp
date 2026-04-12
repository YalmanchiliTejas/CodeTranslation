#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cassert>
#include <stack> 

#define INFLL 2000000000000000000
#define INF 2000000000
#define MOD 1000000007
#define BASE 77747
#define PI acos(-1.0)
#define MAXLEN 29

typedef std::pair <int, int> pii;
typedef long long ll;
typedef std::vector <ll> vll;

using namespace std;

ll add(ll a, ll b) {
	return (a + b) % MOD;
}
ll mul(ll a, ll b) {
	return (a * b) % MOD;
}
ll modPow(ll a, ll b) {
	if (b < 0) return 1;
	ll ans = 1;
	while (b) {
		if (b & 1) ans = mul(ans, a);
		a = mul(a, a);
		b >>= 1;
	}
	return ans;
}
ll dp2[100][100];
ll dp1[100];
ll arr[100];
int n;

ll solve(int s, int e) {
	if (s > e) return 1;
	if (s == e) return modPow(2, arr[s]);
	int len = e - s + 1;
	ll tmp[100];
	for (int i = s; i <= e; i++) tmp[i - s] = arr[i];
	for (int i = 0; i < len; i++) for (int j = 0; j < len; j++) dp1[i] = dp2[i][j] = 0;
	dp1[0] = modPow(2, tmp[0]);
	for (int i = 0; i < len; i++) {
		if (tmp[i] <= tmp[0]) dp2[0][i] = mul(modPow(2, tmp[0] - tmp[i]), 2);
		else dp2[0][i] = 2;
	}
	for (int i = 1; i < len; i++) {
		if (tmp[i] >= tmp[i - 1]) {
			dp1[i] = mul(dp2[i - 1][i - 1], modPow(2, tmp[i] - tmp[i - 1]));
			dp1[i] = add(dp1[i], mul(dp1[i - 1], modPow(2, tmp[i] - tmp[i - 1])));
		} else 
			dp1[i] = add(dp1[i - 1], dp2[i - 1][i]);
		for (int j = i; j < len; j++) {
			if (tmp[i] >= tmp[j]) {
				if (tmp[i - 1] <= tmp[i]) {
					dp2[i][j] = mul(add(dp2[i - 1][i - 1], dp2[i - 1][j]), 
						modPow(2, tmp[i] - max(tmp[i - 1], tmp[j])));
				} else {
					dp2[i][j] = add(dp2[i - 1][j], dp2[i - 1][i]);
				}
			} else {
				dp2[i][j] = mul(2, dp2[i - 1][i]);
			}
		}
	}
	/*
	for (int i = 0; i < len; i++) {
		cout << dp1[i] << endl;
		for (int j = i; j < len; j++) cout << dp2[i][j] << " ";
		cout << endl << "------------" << endl;
	}*/
	return dp1[len - 1];
}

int main() {
	int t;
	t = 1;
	while (t--) {
		for (int i = 0; i < 100; i++) {
			dp1[i] = 0;
			arr[i] = 0;
			for (int j = 0; j < 100; j++) dp2[i][j] = 0;
		}
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ll ans = 1;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1) {
			ans = mul(ans, solve(prev, i - 1));
			ans = mul(ans, 2);
			prev = i + 1;
		}
	}
	ans = mul(ans, solve(prev, n - 1));
	cout << ans << endl;
	}
	return 0;
}
