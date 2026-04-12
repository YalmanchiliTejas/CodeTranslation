#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<ll> h(51);//レベルnバーガーの高さ
vector<ll> p(51);//レベルnバーガーのパティの枚数
ll j_ans;

ll dfs(ll a, ll b) {
	ll ans = 0;
	if (a == 0) return 1;
	if (b >= 1) b--;//一番上のバン
	if (b >= 1) {//レベルa-1バーガー
		if (b >= h[a - 1]) {
			b -= h[a - 1];
			ans += p[a - 1];
		}
		else {
			ans += dfs(a - 1, b);
			b = 0;
		}
	}
	if (b >= 1) {//真ん中のパティ
		b--;
		ans++;
	}
	if (b >= 1) {//レベルa-1バーガー
		if (b >= h[a - 1]) {
			b -= h[a - 1];
			ans += p[a - 1];
		}
		else {
			ans += dfs(a - 1, b);
			b = 0;
		}
	}
	if (b >= 1) {
		b--;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	ll x;
	cin >> x;
	ll cnt = 0;
	h[0] = 1;
	for (int i = 0; i <= n - 1; ++i) {
		h[i + 1] = h[i] * 2 + 3;
	}
	p[0] = 1;
	for (int i = 0; i <= n - 1; ++i) {
		p[i + 1] = 2 * p[i] + 1;
	}
	j_ans = dfs(n, x);
	cout << j_ans << endl;
	return 0;
}
