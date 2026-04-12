#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
#include <chrono>
#include <random>

using namespace std;

typedef long long ll;

void solve() {
	ll n, x, m;
	cin >> n >> x >> m;
	ll slow = x * x % m;
	ll fast = slow * slow % m;
	ll ans = 0;
	while (fast != slow) {
		slow = (slow * slow) % m;
		fast = (fast * fast) % m;
		fast = (fast * fast) % m;
	}
	ll cy_beg = slow;
	slow = x;
	while (n && slow != cy_beg) {
		ans += slow;
		slow = (slow * slow) % m;
		n--;
	}
	ll cy_val = slow;
	ll cy_cnt = 1;
	slow = (slow * slow) % m;
	while (slow != cy_beg) {
		cy_cnt++;
		cy_val += slow;
		slow = (slow * slow) % m;
	}
	ll need = n / cy_cnt;
	ans += need * cy_val;
	n %= cy_cnt;
	while (n) {
		ans += slow;
		slow = (slow * slow) % m;
		n--;
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		//cout << endl;
	}
}