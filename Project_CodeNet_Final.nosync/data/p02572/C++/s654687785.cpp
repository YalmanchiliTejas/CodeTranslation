#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void add(int&a,int b) {
	if ((a += b) >= mod) a -= mod;
}

int mul(int a,int b) {
	return 1ll * a * b % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int now = 0;
	int ans = 0;
	for (int i = 1;i <= n;i++) {
		int x;
		cin >> x;
		add(ans,mul(now,x));
		add(now,x);
	}
	cout << ans;
} 