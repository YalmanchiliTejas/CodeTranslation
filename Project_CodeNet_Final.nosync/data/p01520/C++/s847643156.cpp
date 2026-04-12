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
const int inf = (int)1e9;
const double pi = acos(-1.0);

int main() {
	int n, t, e;
	cin >> n >> t >> e;
	VI x(n); rep(i, n)cin >> x[i];

	int ans = -1;
	rep(i, n) {
		int aa = (t + e) / x[i] * x[i];
		if (t - e <= aa) {
			ans = i + 1;
			break;
		}
	}
	Cout(ans);
}
