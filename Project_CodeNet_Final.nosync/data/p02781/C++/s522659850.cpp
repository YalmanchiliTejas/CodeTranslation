//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

ll ans, cnt, k;
string s;

ll C(int n, int r) {
	if (r > n) return 0;
	ll res = 1;
	for (int i = 1; i <= r; i++)
		res *= (n - i + 1), res /= i;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> s >> k;
	for (int i = 0; i < s.size() && cnt <= k; i++) {
		for (int j = 0; j < s[i] - '0' && cnt <= k; j++) {
			if (j == 1)
				cnt++;
			ll tmp = C((int)s.size() - i - 1, k - cnt);
			for (int p = 1; p <= k - cnt; p++)
				tmp *= 9;
			ans += tmp;
		}
		if (s[i] == '1')
			cnt++;
		if (cnt == k) {
			ans++;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
