#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

string s;
int n, k, ans;

int gun(int a, int b)
{
	if (a < b) return 0;
	if (b < 0) return 0;
	int ret = 1, tmp = a;
	for (int i = 0; i < b; i++) {
		ret *= tmp;
		tmp--;
	}
	for (int i = b; i >= 1; i--) {
		ret /= i;
		ret *= 9;
	}
	return ret;
}

int fun(int i, int r)
{
	if (i == n) {
		if (r) return 0;
		else return 1;
	}
	int ret = 0;
	if (s[i] > '0') {
		int cnt = s[i] - '0';
		if (r > 1) ret += fun(i + 1, r - 1);
		else ret += 1;
		cnt--;
		if (cnt) {
			ret += cnt * gun(n - 1 - i, r - 1);
		}
	}
	if (s[i] == '0') ret += fun(i + 1, r);
	else {
		ret += gun(n - 1 - i, r);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> k;
	n = s.length();
	ans = fun(0, k);
	cout << ans << E;
	//system("pause");
	return 0;
}