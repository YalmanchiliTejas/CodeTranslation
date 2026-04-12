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
	for (int n; cin >> n&&n;) {
		int f[16][16] = {};
		for (int i = n / 2 + 1, j = n / 2, cnt = 1; cnt <= n*n; cnt++) {
			while (f[i][j] != 0) (i += 1) %= n, (j += -1 + n) %= n;
			f[i][j] = cnt;
			(i += 1) %= n, (j += 1) %= n;
		}
		REP(i, n) {
			cout << setw(4) << f[i][0];
			FOR(j, 1, n) {
				cout << setw(4) << f[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}