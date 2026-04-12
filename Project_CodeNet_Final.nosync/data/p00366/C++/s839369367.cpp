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
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
const int inf = 1e9;
const double pi = acos(-1.0);

//約数列挙
vector<int> DivAll(int n) {
	vector<int> ret;
	int i = 1;
	for (; i*i < n; i++)
		if (n%i == 0)ret.push_back(i);
	bool flag = i * i == n;
	if (flag)ret.push_back(i);
	for (i = ret.size() - 1 - flag; i >= 0; --i)
		ret.push_back(n / ret[i]);
	return ret;
}

int main() {
	int n; cin >> n;
	VI t(n); rep(i, n)cin >> t[i]; sort(all(t));
	VI div = DivAll(t.back());
	int ans = 0;
	rep(i, n - 1) {
		auto it = lower_bound(all(div), t[i]);
		if (it != div.end())ans += *it - t[i];
		//cout << *it << " - " << t[i] << endl;
	}
	Cout(ans);
}
