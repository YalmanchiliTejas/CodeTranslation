#include <bits/stdc++.h>

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i+=2)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VC vector<char>
#define FOREACH(x,a) for(auto& (x) : (a) )
using namespace std;

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> v;
	REP(i, h) {
		string a;
		cin >> a;
		bool b = false;
		REP(i, w) {
			if (a[i] == '#') b = true;
		}
		if (b == true) v.push_back(a);
	}
	VI vi;
	REP(i, w) {
		int n = v.size();
		REP(j, v.size()) {
			if (v[j][i] == '.') n--;
		}
		if (n == 0) vi.push_back(i);
	}
	REP(i, v.size()) {
		REP(j, w) {
			bool a = true;
			REP(k, vi.size()) {
				if (vi[k] == j) a = false;
			}
			if (a) {
				cout << v[i][j];
			}
		}
		cout << endl;

	}
	return 0;
}