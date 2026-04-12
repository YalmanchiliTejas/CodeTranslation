#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main()
{
	int r, g, b;
	cin >> r >> g >> b;

	int ans = r * 100 + g * 10 + b;

	if (ans % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
