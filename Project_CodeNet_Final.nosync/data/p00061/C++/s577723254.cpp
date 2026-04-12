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
	//-正解数, 整理番号
	vector<PII> data;
	while (true) {
		int p, s; char c; cin >> p >> c >> s;
		if (p == 0 && s == 0)break;
		data.pb(mp(-s, p));
	}
	sort(all(data));

	//整理番号, 順位
	map<int, int> m;
	m.insert(mp(data[0].second, 1));
	int x = 1;
	FOR(i, 1, sz(data)) {
		if (data[i].first != data[i - 1].first)x++;
		m.insert(mp(data[i].second, x));
	}

	int q;
	while (cin >> q) {
		Cout(m[q]);
	}
}
