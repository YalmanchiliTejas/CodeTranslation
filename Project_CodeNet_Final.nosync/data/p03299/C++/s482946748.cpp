#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, long long> pii;
typedef pair <pii, long long> piii;

const int mod = 1000000007;

int a[110], vis[110][110];
vector <int> all;

long long power(int a, int b){
	if (b <= 0) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

void add(long long &a, long long b){
	a = (a + b % mod + mod) % mod;
}

piii dfs(int l, int r, int now){
	int last = l;
	int left = r - l + 1;
	piii ans = mp(mp(1ll, 1ll), 1ll);
	vector <int> dp(r - l + 2, 0);
	dp[0] = 1;
	for (int i = l; i <= r + 1; i++){
		if (i > r || vis[now + 1][i]){
			if (last > i - 1){
				last = i + 1;
				continue;
			}
			piii tmp = dfs(last, i - 1, now + 1);
			ans.fi.fi = ans.fi.fi * (tmp.fi.fi + tmp.fi.se) % mod;
			ans.fi.se = ans.fi.se * (tmp.fi.se + tmp.fi.fi) % mod;
			ans.se = ans.se * ((tmp.fi.fi + tmp.fi.se) * 2 + tmp.se) % mod;
			left -= i - last;
			last = i + 1;
		}
	}
	ans.se = ans.se * power(2, left) % mod, add(ans.se, -ans.fi.fi - ans.fi.se);
	int cnt = all[now] - (now ? all[now - 1] : 0);
	if (cnt > 1){
		long long xx = ans.fi.fi, yy = ans.fi.se;
		ans.fi.fi = (xx * power(2, cnt - 2) + yy * power(2, cnt - 2)) % mod;
		ans.fi.se = (xx * power(2, cnt - 2) + yy * power(2, cnt - 2)) % mod;
	}
	return ans;
}

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		all.push_back(a[i]);
	}
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for (int i = 0; i < all.size(); i++){ 
		for (int j = 0; j < n; j++){
			vis[i + 1][j] = (a[j] == all[i]);
		}
	}
	piii ans = dfs(0, n - 1, 0);
	printf("%lld\n", (ans.fi.fi + ans.fi.se + ans.se) % mod);
	return 0;
}
