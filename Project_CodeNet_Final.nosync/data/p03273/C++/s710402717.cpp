#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	rep(i, h) cin >> a[i];
	vector<bool> resh(h), resw(w);
	rep(i, h) {
		bool ok = true;
		rep(j, w) {
			if (a[i][j] == '#') ok = false;
		}
		if (ok) resh[i] = true;
	}
	rep(i, w) {
		bool ok = true;
		rep(j, h) {
			if (a[j][i] == '#') ok = false;
		}
		if (ok) resw[i] = true;
	}
	rep(i, h) {
		if (resh[i]) continue;
		rep(j, w) {
			if (resw[j]) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
	return 0;
}
