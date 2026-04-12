#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(V),v.end()));
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef long long ll;
using namespace std;



pair<bool, string> solve(string a0, string a1, string s) {
	string state = a0 + a1;
	FOR(i, 1, s.size()) {
		if (state[i] == 'S') {
			if (s[i] == 'o') {
				state += state[state.size() - 2];
			}
			else {
				if (state[state.size() - 2] == 'W') {
					state += 'S';
				}
				else {
					state += 'W';
				}
			}
		}
		else {
			if (s[i] == 'x') {
				state += state[state.size() - 2];
			}
			else {
				if (state[state.size() - 2] == 'W') {
					state += 'S';
				}
				else {
					state += 'W';
				}
			}
		}
	}
	int ok = 1;
	if (state[0] == 'S') {
		if (s[0] == 'o') {
			if (state[1] != state[state.size() - 2])ok = 0;
		}
		else {
			if (state[1] == state[state.size() - 2])ok = 0;
		}
	}
	else {
		if (s[0] == 'x') {
			if (state[1] != state[state.size() - 2])ok = 0;
		}
		else {
			if (state[1] == state[state.size() - 2])ok = 0;
		}
	}
	if (state[0] == state[state.size() - 1] && ok)return{ true, state.substr(0,state.size() - 1) };
	else return{ false,state.substr(0,state.size() - 1) };
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	vector<pair<bool, string>> p = { solve("S", "S", s), solve("S", "W", s), solve("W", "W", s), solve("W", "S", s) };

	REP(i, 4) {
		if (p[i].first) {
			cout << p[i].second << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
