#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

typedef long long ll;
#define READ(a) int a; cin >> a;
#define READARR(a, n) int a[(n) + 1]; FOR(i, 1, (n)) {cin >> a[i];}
#define READMAT(a, n, m) int a[n + 1][m + 1]; FOR(i, 1, n) {FOR(j, 1, m) cin >> a[i][j];}
#define pb(x) push_back(x)
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
	
	READ(n);
	READARR(p, n);
	
	int sum = 0;
	FOR (i, 1, n) sum += p[i];
	
	int a[n + 1][n + 1] = {}, b[n + 1][n + 1] = {};
	FORD (i, n, 1)
	{
		a[i][i] = p[i];
		b[i][i] = 0;
		
		FOR (j, i + 1, n)
		{
			if (p[i] + b[i + 1][j] > p[j] + b[i][j - 1])
			{
				a[i][j] = p[i] + b[i + 1][j];
				b[i][j] = a[i + 1][j];
			}
			
			else
			{
				a[i][j] = p[j] + b[i][j - 1];
				b[i][j] = a[i][j - 1];
			}
		}
	}
	
	cout << a[1][n] * 2 - sum;
}