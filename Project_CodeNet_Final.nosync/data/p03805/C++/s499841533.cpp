#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;
typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)

bool b[9] = {};
ll N;
ll m[9][9] = {};
bool check() {
	bool v = true;
	repe(i, 1, N) {
		v &= b[i];
	}
	return v;
}
ll cnt = 0;
void dfs(int n)
{
	if (check()) {
		cnt++;
		return;
	}

	repe(i, 1, N) {
		if (n != i) {
			if (m[n][i] == 1 && !b[i]) {
				b[i] = true;
				dfs(i);
				b[i] = false;
			}
		}
	}
}
int main() {
	ll  M; cin >> N >> M;
	rep(i, 0, M) {
		ll a, b;
		cin >> a >> b;
		m[a][b] = 1;
		m[b][a] = 1;
	}

	b[1] = true;
	dfs(1);

	cout << cnt << endl;

	return 0;
}