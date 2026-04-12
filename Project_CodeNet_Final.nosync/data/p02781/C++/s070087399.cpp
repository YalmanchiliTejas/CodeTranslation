#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include <bits/stdc++.h>
#define SIZE 300010
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define ll long long
#define mp make_pair
#define pi acos(-1.0)
#define eps 1e-6
using namespace std;
void io() { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
ll n, ans, k, tmp;
string s;
ll sol(string s) {
	ll ans = 0, tmp = 0;
	ll len = s.length();
	ll fir = s[0] - '0';
	for (ll i = len - 1; i >= 2; --i) {
		for (ll j = i - 1; j; --j) {
			ans += 9ll * 9ll;
		}
	}
	int pos = 1;
	bool f = true;
	rep(i, 1, (s.length() - 1)) if (s[i] != '0') { pos = i; f = false; break; }
	tmp += s[pos] - '0';
	if (!f) for (int i = pos + 1; i < s.length(); ++i) tmp += 9ll;
	/*if (!f) */for (int i = 1; i < s.length(); ++i) tmp += 9ll * (fir - 1);
	return ans + tmp;
}
int main() {
	io(); cin >> s >> k;
	ll len = s.length();
	ll fir = s[0] - '0';
	if (k == 1) cout << 9 * (len - 1) + fir;
	else if (k > len) cout << 0;
	else if (k == 2) cout << sol(s);
	else if (k == 3) {
		for (ll i = len - 1; i >= 3; --i) {
			for (ll j = i - 1; j >= 2; --j) {
				for (ll k = j - 1; k; --k) {
					ans += 9ll * 9ll * 9ll;
				}
			}
		}
		for (int i = 1; i < s.length() - 1; ++i) {
			for (int j = i + 1; j < s.length(); ++j) {
				ans += 9ll * 9ll * (fir - 1ll);
				//tmp += (s[i] - '0') * (s[j] - '0');
			}
		}
		int pos = 1, ps = 2; bool ff = false;
		rep(i, 1, (s.length() - 1)) if (s[i] != '0') { ff = true; pos = i; break; }
		rep(i, (pos + 1), (s.length() - 1)) if (s[i] != '0') { ps = i; break; }
		/*for (int i = pos + 1; i < s.length() - 1; ++i) {
			for (int j = ps + 1; j < s.length(); ++j) {
				tmp += 9ll * 9ll;
			}
		}*/
		string ss;
		rep(i, pos, (s.length() - 1)) ss.push_back(s[i]);
		if (ff) tmp += sol(ss);
		cout << ans + tmp;
	}
}