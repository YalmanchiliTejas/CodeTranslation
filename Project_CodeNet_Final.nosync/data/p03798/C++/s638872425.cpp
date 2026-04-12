#include <bits/stdc++.h>
#include <regex>
using namespace std;
typedef long long ll;

#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
#define SIZE(array) (sizeof(array) / sizeof(array[0]))

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

#define MAX_V 100000

#define MOD 1000000007L
#define INF 100000000000

bool next_type(bool prev, bool current, bool honest) {
	return prev ^ !current ^ !honest;
}

signed main() {
	int n;
	string s;
	cin >> n >> s;
	string c[4] = { "SS", "SW", "WS", "WW" };
	string res = "";
	bool end = false;
	for (size_t i = 0; i < 4 && !end; i++) {
		// cout << i << endl;
		res = c[i];
		for (size_t j = 1; j < s.size() - 1; j++) {
			bool next = next_type(res[j - 1] == 'S', s[j] == 'o', res[j] == 'S');
			res += "WS"[next];
			// cout << res << endl;
		}
		int last = s.size() - 1;
		int ln = next_type(res[last - 1] == 'S', s[last] == 'o', res[last] == 'S');
		int fn = next_type(res[last] == 'S', s[0] == 'o', res[0] == 'S');
		// printf("ln: %c\nfn: %c\n", "WS"[ln], "WS"[fn]);
		if ("WS"[ln] == res[0] && "WS"[fn] == res[1]) {
			end = true;
			break;
		}
	}
	cout << (end ? res : "-1") << endl;
}
