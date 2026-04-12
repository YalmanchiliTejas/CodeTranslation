#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 0x7ffffff;
const int mod = 1000000007;

ll n, x;
ll p[51];
ll h[51];

ll dfs(ll now_level = n, ll tmp = x) {
	ll ans = 0;
	if (now_level == 0) ans++;
	if (tmp >= 1) tmp--;
	if (tmp >= 1) {
		if (tmp >= h[now_level - 1]) {
			tmp -= h[now_level - 1];
			ans += p[now_level - 1];
		}
		else {
			ans += dfs(now_level - 1, tmp);
			tmp = 0;
		}
	}
	if (tmp >= 1) {
		tmp--;
		ans++;
	}
	if (tmp >= 1) {
		if (tmp >= h[now_level - 1]) {
			tmp -= h[now_level - 1];
			ans += p[now_level - 1];
		}
		else {
			ans += dfs(now_level - 1, tmp);
			tmp = 0;
		}
	}
	if (tmp >= 1) tmp--;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;
	p[0] = 1;
	for (int i = 1; i <= n; ++i) p[i] = 2 * p[i - 1] + 1;
	h[0] = 1;
	for (int i = 1; i <= n; ++i) h[i] = 2 * h[i - 1] + 3;
	ll j_ans = dfs();
	cout << j_ans << endl;
	return 0;
}
