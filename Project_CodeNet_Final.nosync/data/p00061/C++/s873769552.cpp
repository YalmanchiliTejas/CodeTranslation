#include<iostream>
#include<iomanip>
#include<algorithm>
#include<array>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<functional>
#include<limits>
#include<list>
#include<map>
#include<numeric>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<queue>
#include<vector>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(a) (a).begin(),(a).end()
#define DUMP(o) {cerr<<#o<<" "<<o<<endl;}
#define DUMPC(o) {cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
const int MOD = 1e9 + 7;

signed main() {
	int p, s; char c;
	vector<pii> b;
	while (cin >> p >> c >> s&&p) {
		b.push_back(pii(s, p));
	}
	sort(ALL(b), greater<pii>());
	vector<int> r(b.size() + 1);

	r[b[0].second] = 1;
	FOR(i, 1, b.size()) {
		if (b[i].first == b[i - 1].first)r[b[i].second] = r[b[i - 1].second];
		else r[b[i].second] = r[b[i - 1].second] + 1;
	}
	for (int q; cin >> q;) {
		cout << r[q] << endl;
	}
	return 0;
}