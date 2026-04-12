#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <array>
#include <queue>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <utility>
#include <bitset>
#include <complex>
#include <algorithm>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <climits>
#include <random>
#include <functional>
#include <sstream>
#include <iomanip>

using namespace std;

#define rep(i, n) for(int i=0; i<(n); i++)
#define FOR(i, m, n) for(int i=(m);i<(n);i++)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort((x).begin(),(x).end())
#define REVE(x) reverse((x).begin(),(x).end())
#define mp make_pair
#define pb push_back
#define Cout(x) cout << (x) << endl;
#define dump(x) cout << #x << " = " << (x) << endl;
#define forauto(i, a) for(auto i : a)cout << i << " "; puts("");

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef complex<double> CD;

int main() {
	bool first = true;
	while (true) {
		int n; cin >> n;
		if (n == 0)break;

		if (!first)puts("");
		first = false;

		vector<pair<int, pair<int, string>>> ans;
		rep(i, n) {
			string s; int a, b, c;
			cin >> s >> a >> b >> c;
			ans.pb(mp(a * 3 + c, mp(n - i, s)));
		}
		SORT(ans); REVE(ans);

		rep(i, n) {
			cout << ans[i].second.second << "," << ans[i].first << endl;
		}
	}
}
