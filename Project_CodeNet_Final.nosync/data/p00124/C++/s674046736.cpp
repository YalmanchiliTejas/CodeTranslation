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
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

//#define int long long
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) {cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) {cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
const int MOD = 1e9 + 7;

signed main() {
	tuple<int, int, string> a[10];
	for (int n, h = 0; cin >> n&&n; h++) {
		if (h > 0)cout << endl;
		rep(i, 0, n) {
			string name; cin >> name;
			int w, l, d; cin >> w >> l >> d;
			a[i] = make_tuple(w * 3 + d, -i, name);
		}
		sort(a, a + n);
		rrep(i, 0, n) {
			cout << get<2>(a[i]) << "," << get<0>(a[i]) << endl;
		}
	}
	return 0;
}