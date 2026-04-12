#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	string ans = "";
	for (char i = 'a'; i <= 'z'; ++i) {
		int k = 100;
		rep(j, n) {
			int a = count(all(s[j]), i);
			k = min(k, a);
		}
		if (k == 100) continue;
		while (k > 0) {
			ans += i;
			k--;
		}
	}

	sort(all(ans));
	cout << ans << endl;

	return 0;
}
