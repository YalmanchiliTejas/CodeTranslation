#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
#include<iomanip>
#include<stack>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> e(n, vector<bool>(n, false));
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		e[a][b] = true;
		e[b][a] = true;
	}

	vector<int> v(n);
	rep(i, n) v[i] = i;

	int ans = 0;
	do {
		if (v[0] != 0) break;
		bool flag = true;
		rep(i, n - 1) {
			if (!e[v[i]][v[i + 1]]) flag = false;
		}
		if (flag) ans++;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}