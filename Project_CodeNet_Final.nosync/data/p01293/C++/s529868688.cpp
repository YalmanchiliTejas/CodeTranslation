#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

map<char, int> m;

int judge(char c1, char c2, vector<string> v) {
	int id = -1, res = -1;

	rep(i, v.size()) {
		if(v[i][1] == c1) {
			if(res < m[v[i][0]]) {
				res = m[v[i][0]];
				id = i;
			}
		}
	}

	if(id != -1) return id;

	rep(i, v.size()) {
		if(v[i][1] == c2) {
			if(res < m[v[i][0]]) {
				res = m[v[i][0]];
				id = i;
			}
		}
	}

	if(id != -1) return id;

	rep(i, v.size()) {
		if(res < m[v[i][0]]) {
			res = m[v[i][0]];
			id = i;
		}
	}
	return id;
}

int main() {
	char c;
	vector<vector<string> > v(4, vector<string>(13));

	REP(i, 1, 10) {
		m['0'+i] = i;
	}

	m['T'] = 10;
	m['J'] = 11;
	m['Q'] = 12;
	m['K'] = 13;
	m['A'] = 14;

	while(cin >> c) {
		if(c == '#') break;

		rep(i, 4) {
			rep(j, 13) {
				cin >> v[i][j];
			}
		}

		int a = 0, b = 0, id = 0;
		rep(i, 13) {
			vector<string> t;
			rep(j, 4) {
				t.push_back(v[j][i]);
			}

			id = judge(c, v[id][i][1], t);
			if(id & 1) {
				b++;
			} else {
				a++;
			}
		}

		if(a > b) {
			cout << "NS " << a - 6 << endl;
		} else {
			cout << "EW " << b - 6 << endl;
		}
	}


	return 0;
}