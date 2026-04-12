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

map<char, int> count(string s) {
	map<char, int> m = {};
	for (size_t i = 0; i < s.size(); i++) {
		m[s[i]]++;
	}
	return m;
}

void ca(int n, vector<string>& s) {
	map<char, int> m = {};
	for (size_t i = 'a'; i <= 'z'; i++) {
		m[i] = 50;
	}
	for (size_t i = 0; i < n; i++) {
		map<char, int> m2 = count(s[i]);
		for (size_t i = 'a'; i <= 'z'; i++) {
			m[i] = min(m[i], m2[i]);
		}
	}
	for (auto& e: m) {
		// cout << e.first << ": " << e.second << endl;
		for (size_t i = 0; i < e.second; i++) {
			cout << e.first;
		}
	}
	cout << endl;
}

signed main() {
	int n;
	cin >> n;
	vector<string> s;
	for (size_t i = 0; i < n; i++) {
		string t;
		cin >> t;
		s.push_back(t);
	}
	ca(n, s);
}
