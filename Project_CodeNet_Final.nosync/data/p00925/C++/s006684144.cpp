#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144*2LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

unsigned long xor128() {
	static unsigned long x = 123456789, y = 362436069, z = 521288629, w = time(NULL);
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

void init() {
}

void solve() {
	string s;
	cin >> s;
	int a = 0;
	cin >> a;
	int ans = 0;
	{
		int now = s[0] - '0';
		for (int i = 1; i < s.length();i += 2) {
			if (s[i] == '+') {
				now += s[i + 1] - '0';
			}
			else {
				now *= s[i + 1] - '0';
			}
		}
		if (now == a) {
			ans |= 2;
		}
	}
	{
		stack<int> geko;
		int now = s[0] - '0';
		for (int q = 1; q < s.length(); q += 2) {
			if (s[q] == '+') {
				geko.push(now);
				now = s[q + 1] - '0';
			}
			else {
				now *= s[q + 1] - '0';
			}
		}
		while (geko.empty() == false) {
			now += geko.top();
			geko.pop();
		}
		if (now == a) {
			ans |= 1;
		}
	}
	string answer = "IMLU";
	cout << answer[ans] << endl;
}
int main() {
	init();
	solve();
}
