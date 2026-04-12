#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)

typedef pair<int, int> pii;

int main() {
	int n;
	bool f = false;
	while (cin >> n, n) {
		if (f) puts("");
		
		string str[10];
		vector<pii> v(n);
		
		REP(i, n) {
			int a, b, c;
			cin >> str[i] >> a >> b >> c;
			int score = 3*a + c;
			v[i] = pii(score, -i);
		}
		sort(v.begin(), v.end(), greater<pii>());
		
		REP(i, n) printf("%s,%d\n", str[-v[i].second].c_str(), v[i].first);
		
		f = true;
	}
	return 0;
}