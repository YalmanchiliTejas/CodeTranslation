#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<int, int> pos;
	long long n;
	int x, m;
	cin >> n >> x >> m;
	long long a[m + 1];
	a[0] = x;
	pos[x] = 0;
	int st = -1;
	for(int i = 1; ;i++) {
		a[i] = (a[i - 1] * a[i - 1]) % m;
		if(pos.find(a[i]) != pos.end()) {
			st = i;
			break;
		}
		pos[a[i]] = i;
	}
	assert(st != -1);
	long long ans = 0;
	for(int i = 0; i < min(n, 1ll * st); i++) ans += a[i];
	long long per = 0;
	for(int i = pos[a[st]]; i < st; i++) per += a[i];
	n -= st;
	if(n >= st - pos[a[st]]) {
		long long need = n / (st - pos[a[st]]);
		ans += need * per;
		n %= (st - pos[a[st]]);
	}
	for(int i = pos[a[st]]; i < st and n > 0; i++) ans += a[i], n--;
	cout << ans << endl;
	return 0;
}