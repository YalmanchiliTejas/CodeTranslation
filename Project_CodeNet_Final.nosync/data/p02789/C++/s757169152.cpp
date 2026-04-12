#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

typedef long long ll;
#define READ(a) int a; cin >> a;
#define READARR(a, n) int a[(n) + 1] = {}; FOR(i, 1, (n)) {cin >> a[i];}
#define READMAT(a, n, m) int a[n + 1][m + 1] = {}; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define print(a, n) FOR (i, 1, n) cout << a[i] << " "; cout << endl;
#define printmat(a, n, m) FOR (i, 1, n) {FOR (j, 1, m) cout << a[i][j] << " "; cout << endl;} cout << endl;
#define pb push_back
#define fi first
#define se second
#define vi vector <int>
#define pi pair <int, int>
#define vpi vector <pi>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
const ll inf = 1e18;
const ll mod = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	if (a == b) cout << "Yes";
	else cout << "No";
}