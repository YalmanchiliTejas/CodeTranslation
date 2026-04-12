#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 7;
const LL LINF = INF * INF;

const int MAX = 3007;
int n;
LL dp[MAX][MAX];
int a[MAX];
char visited[MAX][MAX];

LL get(int l, int r)
{
	if (l == r)
	{
		if (n & 1)
			return a[l];
		else
			return -a[l];
	}
	
	if (visited[l][r])
		return dp[l][r];
	
	visited[l][r] = 1;
	int zab = n - (r - l + 1);
	LL res = 0;
	
	if (zab & 1)
		res = min(get(l + 1, r) - a[l] , get(l, r - 1) - a[r]);
	else
		res = max(get(l + 1, r) + a[l] , get(l, r - 1) + a[r]);
	
	return dp[l][r] = res;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	//freopen("In.txt", "r", stdin);
	//freopen("In.txt", "w", stdout);

	cin >> n;
	FOR(i, 0, n)
		cin >> a[i];

	cout << get(0, n - 1) << endl;
	cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}

