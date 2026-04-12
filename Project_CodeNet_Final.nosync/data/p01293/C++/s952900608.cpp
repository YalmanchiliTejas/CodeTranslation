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
	iostream::sync_with_stdio(false);
	cout << fixed << setprecision(20);
}

#define int ll

void solve(){
	while (true) {
		string s;
		cin >> s;
		if (s == "#") return;
		vector<vector<string>> inputs;
		REP(i, 4) {
			inputs.push_back(vector<string>());
			REP(q, 13) {
				string s;
				cin >> s;
				inputs.back().push_back(s);
			}
		}
		map<char, int> calc;
		for (int i = 2; i <= 9; ++i) {
			calc[i + '0'] = i;
		}
		calc['T'] = 10;
		calc['J'] = 11;
		calc['Q'] = 12;
		calc['K'] = 13;
		calc['A'] = 14;
		int ans[2] = { -6,-6 };
		int nowTurn = 0;
		REP(i, 13) {
			int winning = -1;
			int now_max = -1;
			REP(q, 4) {
				int go = calc[inputs[q][i][0]];
				if (inputs[q][i][1] == s[0]) {
					go += 100;
				}
				if (inputs[q][i][1] == inputs[nowTurn][i][1]) {
					go += 20;
				}
				if (go > winning) {
					winning = go;
					now_max = q;
				}
			}
			ans[now_max & 1]++;
			nowTurn = now_max;
		}
		if (ans[0] > 0) {
			cout << "NS " << ans[0] << endl;
		}
		else {
			cout << "EW " << ans[1] << endl;
		}
	}
}

#undef int
int main() {
	init();
	solve();
}
