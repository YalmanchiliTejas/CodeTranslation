#include <bits/stdc++.h>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 123;
const int mod = 1e9 + 7;
const ll inf = 1e18 + 9;

inline void boost () {
	ios_base::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
}
int n, m, cnt;
char a[9][9];

int main () {
	boost ();
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
		for (int j = 1;j <= m;j ++) {
			cin >> a[i][j];
			if (a[i][j] == '#') cnt ++;
		}
	if (cnt == n + m - 1) cout << "Possible";
	else cout << "Impossible";

	return 0;
}

        