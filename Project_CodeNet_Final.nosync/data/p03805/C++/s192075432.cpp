#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n; i++)
#define c(ans) cout << (ans) << '\n'
using namespace std;
int n, m, a = 0,b,c;string s, t;
int main(void) {
	cin >> n >> m;
	vector<int> k(n);
	rep(i, n) k[i] = i + 1;
	bool v[10][10];
	rep(i, 10) {
		rep(j, 10) {
			v[i][j] = false;
		}
	}
	rep(i, m) {
		cin >> b >> c;
		v[b][c] = true;
		v[c][b] = true;
	}
	do {
		bool g = true;
		rep(i, n - 1) {
			if (!v[k[i]][k[i + 1]])
				g = false;
		}
		if (g) ++a;
	} while (next_permutation(k.begin() + 1, k.end()));
	c(a);
}