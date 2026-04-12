#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
ll c[50][50] = {};
ll A[50] = {};
ll B[50] = {};
bool v[50] = {};
ll N, M;
ll cnt = 0;

void dfs(int i) {
	rep(j, 0, N) {
		if (i != j && c[i][j] == 1 && !v[j])
		{
			v[j] = true;
			dfs(j);
			v[j] = false;
		}
	}

	bool allvisited = true;
	rep(j, 0, N) {
		if (!v[j]) {
			allvisited = false;
			break;
		}
	}
	if (allvisited) {
		cnt++;
	}
}
int main() {
	cin >> N >> M;

	rep(i, 0, M) {
		ll a, b; cin >> a >> b;
		c[a - 1][b - 1] = 1;
		c[b - 1][a - 1] = 1;
	}

	v[0] = true;
	dfs(0);

	cout << cnt << endl;
	return 0;
}