#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#define int long long
#define mod 1000000007
#define for0(i, n) for(int i = 0; i < (n); i++)
#define for1(i, n) for(int i = 1; i <= (n);i++)
#define mp make_pair
using namespace std;
int get() { int r; cin >> r; return r; }
string s; int k, ans;
signed main() {
	cin >> s >> k;
	if (k == 1) {
		cout << s[0] - '0' + (s.size() - 1) * 9 << endl;
		return 0;
	}
	else if (k == 2) {
		string s1;
		int ans = 0;
		for1(i, s.size())s1 += '0';
		for0(i, s.size()) {
			for (int j = i + 1; j < s.size(); j++) {
				for (char c1 = '1'; c1 <= '9'; c1++)for (char c2 = '1'; c2 <= '9'; c2++) {
					s1[i] = c1; s1[j] = c2;
					if (s >= s1)ans++;
					s1[i] = '0'; s1[j] = '0';
				}
			}
		}
		cout << ans << endl;
		return 0;
	}
	else {
		int ans = (s.size() - 1)*(s.size() - 2)*(s.size() - 3) / 6 * 9 * 9 * 9;
		ans += (s[0] - '1')*(s.size() - 1)*(s.size() - 2) / 2 * 9 * 9;
		string s1; s1 += s[0];
		for1(i, s.size() - 1)s1 += '0';
		for1(i, s.size() - 1) {
			for (int j = i + 1; j < s.size(); j++) {
				for (char c1 = '1'; c1 <= '9'; c1++)for (char c2 = '1'; c2 <= '9'; c2++) {
					s1[i] = c1; s1[j] = c2;
					if (s >= s1)ans++;
					s1[i] = '0'; s1[j] = '0';
				}
			}
		}
		cout << ans << endl;
	}
}