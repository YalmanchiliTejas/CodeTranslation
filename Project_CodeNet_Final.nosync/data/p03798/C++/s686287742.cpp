#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,a,n) for(int i = (a); i < (n); ++i)
using namespace std;
typedef long long ll;

string next(char prev1, char prev2, char s) {
	if ((s == 'o' && prev1 == 'S') || (s == 'x' && prev1 == 'W')) {
		return prev2 == 'S' ? "S" : "W";
	}
	if ((s == 'o' && prev1 == 'W') || (s == 'x' && prev1 == 'S')) {
		return prev2 == 'S' ? "W" : "S";
	}
}

void Main()
{
	int N; cin >> N;
	string s; cin >> s;
	s = s + s;
	string pattern[4] = {"SS", "SW", "WS", "WW"};
	rep(i, 4) {
		string res = pattern[i];
		REP(j,2,N + 2) {
			string _next = next(res[j - 1], res[j - 2], s[j - 1]);
			res += _next;
			if (j == N && _next[0] != res[0]) {
				break;
			}
			if (j == N + 1 && _next[0] == res[1]) {
				cout << res.substr(0, N) << endl;
				return;
			}
		}
	}
	cout << -1 << endl;
}

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout << fixed << setprecision(15);
	Main();
}
