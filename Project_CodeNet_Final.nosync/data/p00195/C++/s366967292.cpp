#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define Cout(x) cout << (x) << endl
#define Cout2(x, y) cout << (x) << " " << (y) << endl
#define dump(x) cout << #x << " = " << (x) << endl;
#define forauto(i, a) for(auto i : a)cout << i << " "; puts("");
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
const int inf = 1e9;
const double pi = acos(-1.0);

int main() {
	while (true) {
		int x, y; cin >> x >> y;
		if (x == 0 && y == 0)break;

		VI s(5); s[0] = x + y;
		FOR(i, 1, 5) {
			int a, b; cin >> a >> b;
			s[i] = a + b;
		}

		auto ans = max_element(all(s));
		Cout2((char)('A' + (ans - s.begin())), *ans);
	}
}
