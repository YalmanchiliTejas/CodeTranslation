#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    long long n;
    int x, m;
    cin >> n >> x >> m;
    long long ans = x;
    vector<int> rep(m + 1, -1);
    rep[x] = 0;
    vector<long long> ac(m + 1, 0);
    ac[0] = x;
    int prev = x;
    int i, cur;
    for (i = 1; i < n; i++) {
        cur = (prev * 1ll * prev) % m;
        if (rep[cur] != -1) break;
        rep[cur] = i;
        prev = cur;
        ans += cur;
        ac[i] = ans;
    }
    if (i != n && cur != 0) {
        long long loop = ac[i - 1];
        if (rep[cur] != 0)
            loop -= ac[rep[cur] - 1];
        ans += loop * ((n - i) / (i - rep[cur]));
        long long resto;
        if (rep[cur] - 1 + (n - i) % (i - rep[cur]) >= 0)
            resto = ac[rep[cur] - 1 + (n - i) % (i - rep[cur])];
        if (rep[cur] != 0)
            resto -= ac[rep[cur] - 1];
        ans += resto;
    }
    cout << ans << endl;
	return 0;
}