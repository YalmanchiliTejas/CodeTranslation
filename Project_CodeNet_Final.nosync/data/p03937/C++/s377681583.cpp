#include <algorithm>
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define REP(i,n) for(int i=0;i<n;++i)
#define RREP(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<n;++i)
#define RFOR(i,m,n) for(int i=m-1;i>=n;--i)
#define ALL(v) v.begin(),v.end()
#define pb(a) push_back(a)
#define INF 1000000001
#define MOD 1000000007

using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int w, h;
	cin >> h >> w;
	char c;
	int cnt = 0;
	REP(i, w) {
		REP(j, h) {
			cin >> c;
			if (c == '#') cnt++;
		}
	}
	if (cnt == h + w - 1) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	return 0;
}