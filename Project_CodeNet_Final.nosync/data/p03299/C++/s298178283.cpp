//21
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 101;
const int lbt = 1e9 + 7;
const int inf = 1e9;

int n;
int h[maxn];

int fast_pow(int a, int t);
pair<int, int> cal(int l, int r, int bot);

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	pair<int, int> ans = cal(1, n, 0);
	printf("%d", (ans.first + ans.second) % lbt);
	return 0;
}

int fast_pow(int a, int t) {
	int ans = 1;
	for (int i = 31; i >= 0; i--) {
		ans = (long long)ans * ans % lbt;
		if (t >> i & 1) ans = (long long)a * ans % lbt;
	}
	return ans;
}

pair<int, int> cal(int l, int r, int bot) {
	int minh = inf;
	for (int i = l; i <= r; i++) {
		minh = min(minh, h[i]);
	}
	int g = 0;
	int prod = 1;
	int prod0 = 1;
	int last = l;
	for (int i = l; i <= r; i++) {
		if (h[i] == minh) {
			g++;
			if (last < i) {
				pair<int, int> cur = cal(last, i - 1, minh);
				prod = (long long)prod * ((long long)2 * cur.first + cur.second) % lbt;
				prod0 = (long long)prod0 * cur.first % lbt;
			}
			last = i + 1;
		}
	}
	if (last <= r) {
		pair<int, int> cur = cal(last, r, minh);
		prod = (long long)prod * ((long long)2 * cur.first + cur.second) % lbt;
		prod0 = (long long)prod0 * cur.first % lbt;
	}
	int dp0 = (long long)fast_pow(2, minh - bot) * prod0 % lbt;
	int dp1 = ((long long)fast_pow(2, g) * prod + (long long)(lbt - 2) * prod0) % lbt;
	return make_pair(dp0, dp1);
}