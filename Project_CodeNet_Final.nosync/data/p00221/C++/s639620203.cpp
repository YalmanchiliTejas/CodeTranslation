#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n, m) {
		vector<int>v(m);
		iota(v.begin(), v.end(), 1);
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			string s; cin >> s;
			if (v.size() == 1)continue;
			string ans;
			if (i % 3 == 0 || i % 5 == 0) {
				if (i % 3 == 0)ans += "Fizz";
				if (i % 5 == 0)ans += "Buzz";
			}
			else ans = to_string(i);
			if (ans != s) {
				v.erase(v.begin() + cnt);
				cnt %= v.size();
			}
			else cnt = (cnt + 1) % v.size();
		}
		rep(i, v.size()) {
			cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');
		}
	}
}