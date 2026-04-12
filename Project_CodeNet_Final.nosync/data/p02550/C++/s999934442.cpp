#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

long long n;
int x, m;
int vis[100009];
long long tmp[100009];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> x >> m;
	if (x == 0) {
		cout << 0 << endl;
		return 0;
	}
	memset(vis, 0xff, sizeof(vis));
	long long ans = -1, pre, cur;
	tmp[0] = x;
	vis[x] = 0;
	pre = x;
	for (int i = 1; i < n; i++) {
		cur = pre * pre;
		cur %= m;
		if (cur == 0) {
			ans = tmp[i - 1];
			break;
		}
		if (vis[cur] >= 0) {
			if (vis[cur] > 0) ans = tmp[vis[cur] - 1];
			else ans = 0;
			long long k = n - vis[cur];
			long long tt = tmp[i - 1];
			int d = i - vis[cur];
			if (vis[cur] > 0) tt -= tmp[vis[cur] - 1];
			ans += tt * (k / d);
			if (k % d) {
				ans += tmp[k % d - 1 + vis[cur]];
				if (vis[cur] > 0)
					ans -= tmp[vis[cur] - 1];
			}
			break;
		}
		tmp[i] = cur + tmp[i - 1];
		vis[cur] = i;
		pre = cur;
	}
	if (ans < 0) ans = tmp[n - 1];
	cout << ans << endl;
	//system("pause");
	return 0;
}
