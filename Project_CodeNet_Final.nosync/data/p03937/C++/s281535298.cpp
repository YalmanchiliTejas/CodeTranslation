//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef long double ld ;

//#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) / b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 + 10 ;
const int MAXN = 4194305;
const int MLOG = 17;
const int NMAX = 20;

signed main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	int ans[n + m - 1] = {};
	bool p = true;
	char ch;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			cin >> ch;
			if(ch == '#') ans[i + j]++;
			if(ans[i + j] > 1) p = false;
		}
	cout << ((p) ? "Possible" : "Impossible");
}
