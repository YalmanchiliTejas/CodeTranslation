#include<bits/stdc++.h>
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
#define rep(i,n)for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int res;
void judge(int i, int j) {
	if (i == j&&i == res)puts("U");
	else if (i == res)puts("L");
	else if (j == res)puts("M");
	else puts("I");
}
int C(int a, int b, char c) {
	if (c == '+')return a + b;
	return a*b;
}
int calc(string s) {
	int res = s[0] - '0';
	char c;
	for (int i = 1; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')res = C(res, s[i] - '0', c);
		else c = s[i];
	}
	return res;
}
int main() {
	string s, t, k; cin >> s >> res; t = s;
	int d = 0;
	for (char c : s) {
		if (c == '+') {
			d += calc(k); k = "";
		}
		else k += c;
	}
	d += calc(k);
	judge(calc(s), d);
}