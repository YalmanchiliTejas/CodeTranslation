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
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
const int inf = (int)1e9;
const long long mod = (long long)1e9 + 7;
const double pi = acos(-1.0);

int main() {
	int n; cin >> n;
	VI h(n); rep(i, n)cin >> h[i];

	int ans = 0;
	rep(i, n) {
		bool flag = true;
		rep(j, i)if (h[i] < h[j])flag = false;
		ans += flag;
	}
	Cout(ans);
}