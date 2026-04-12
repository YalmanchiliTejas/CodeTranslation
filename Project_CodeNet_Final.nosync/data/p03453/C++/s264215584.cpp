#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#include<list>
#include<iomanip>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
#include<random>
#include<ctime>
#include<cstdlib>
#include<unordered_map>
#include<string.h>
#include<iostream>
#define mod 1000000007
#define int long long
#define P pair<int,int>//距離　頂点
using namespace std;

int dp[100000];
int p[100000];
vector<P>V[100000];
vector<P>S;
int l[100000];
int r[100000];
signed main() {
	int n, m; cin >> n >> m;
	int a, b; cin >> a >> b; a--; b--;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z; x--; y--; z *= 2;
		V[x].push_back({ z,y });
		V[y].push_back({ z,x });
	}
	priority_queue<P, vector<P>, greater<P>>Q;
	memset(l, 0x3f, sizeof(l));
	memset(r, 0x3f, sizeof(r));
	l[a] = 0; r[b] = 0;
	Q.push({ 0,a });
	while (Q.size()) {
		P i = Q.top(); Q.pop();
		if (l[i.second] < i.first)continue;
		for (P t : V[i.second]) {
			if (i.first + t.first < l[t.second]) {
				l[t.second] = i.first + t.first;
				Q.push({ l[t.second],t.second });
			}
		}
	}
	Q.push({ 0,b });
	while (Q.size()) {
		P i = Q.top(); Q.pop();
		if (r[i.second] < i.first)continue;
		for (P t : V[i.second]) {
			if (i.first + t.first < r[t.second]) {
				r[t.second] = i.first + t.first;
				Q.push({ r[t.second],t.second });
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (l[i] + r[i] == l[b]) {
			S.push_back({ l[i], i });
		}
	}
	dp[a] = 1;
	sort(S.begin(), S.end());
	for (P k : S) {
		for (P u : V[k.second]) {
			if (k.first + u.first == l[u.second]) {
				dp[u.second] += dp[k.second];
				dp[u.second] %= mod;
			}
		}
	}
	S.clear();
	for (int i = 0; i < n; i++) {
		if (l[i] + r[i] == l[b]) {
			S.push_back({ r[i], i });
		}
	}
	p[b] = 1;
	sort(S.begin(), S.end());
	for (P k : S) {
		for (P u : V[k.second]) {
			if (k.first + u.first == r[u.second]) {
				p[u.second] += p[k.second];
				p[u.second] %= mod;
			}
		}
	}
	int ans = dp[b] * dp[b] % mod;
	for (int i = 0; i < n; i++) {
		if (l[i] + r[i] != l[b])continue;
		if (l[i] == l[b] / 2) {
			ans -= (dp[i] * p[i] % mod)*(dp[i] * p[i] % mod)%mod;
			ans %= mod;
		}
		else if(l[i]<l[b]/2){
			for (P j : V[i]) {
				if (l[i] +j.first+ r[j.second] == l[b]) {
					if (l[j.second] > l[b] / 2) {
						ans -= (dp[i] * p[j.second] % mod)*(dp[i] * p[j.second] % mod)%mod;
						ans %= mod;
					}
				}
			}
		}
	}
	while (ans < 0) {
		ans += mod;
	}
	ans %= mod;
	cout << ans << endl;
}