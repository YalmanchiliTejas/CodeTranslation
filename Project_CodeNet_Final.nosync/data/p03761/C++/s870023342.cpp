#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	vector<int> v(26);
	rep(j, s[0].size()) v[(int) (s[0][j] - 'a')]++;
	for (int i = 1; i < n; i++) {
		vector<int> u(26);
		rep(j, s[i].size()) u[(int) (s[i][j] - 'a')]++;
		rep(j, 26) {
			v[j] = min(v[j], u[j]);
		}
	}
	rep(i,26) {
		rep(j,v[i]) {
			cout << (char) (i + 'a');
		}
	}
	cout << endl;
}

int main() {
	solve();
	return 0;
}