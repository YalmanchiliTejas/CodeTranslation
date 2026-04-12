#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using IP = pair<int, int>;

const ll INF = 1LL << 62;
#define atcoder(int)1e9+7
#define Endl endl
#define mp make_pair
#define all(v) v.begin(),v.end()
#define pb push_back

ll gcd(ll a, ll b) {//最大公約数
	if (a%b == 0)return b;
	else gcd(b, a%b);
}

ll lcm(ll a, ll b) {//最小公倍数
	return (a / gcd(a, b))*b;
}

int n, m;
bool p[8][8];
bool j[8] = { false };
int ans = 0;

void dfs(int v) {

	bool c = false;
	for (int i = 0; i < n; i++) {
		if (!j[i]) c = true;
	}
	if (!c)ans++;

	for (int i = 0; i < n; i++) {
		if (p[v][i] == false)continue;
		if (j[i])continue;
		j[i] = true;
		dfs(i);
		j[i] = false;
	}

}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		p[a][b] = p[b][a] = true;
	}

	for (int k = 0; k < n; k++)	j[k] = false;
	j[0] = true;
	dfs(0);
	cout << ans << endl;
	return 0;
}