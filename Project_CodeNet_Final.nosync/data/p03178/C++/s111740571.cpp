#include "iostream"
#include "fstream"
#include "algorithm"
#include "iomanip"
#include "stack"
#include "queue"
#include "string"
#include "vector"
#include "map"
#include "set"
#include "list"
#include "deque"
#include "complex"
#include "bitset"
#include "cmath"
#include "unordered_set"
#include "unordered_map"
#include "iterator"
#include <ctime>
#include <cassert>
#include "numeric"
#include <cstdio>

using namespace std;

//#define f(i,n) for(int i=0; i<n;i++) 
//#define rf(i, n) for(int i=n-1;i>=0;i--)
//#define forn(i, j, n) for(int i=j; i<n; i++)
//#define ff(i, j, n) f(i, n)f(j, n)
#define pb push_back
#define maxi(a,b) a = max(a, b);
#define mini(a,b) a = min(a, b);
#define endl '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sqr(x) ((x) * (x))
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;
//typedef long long ll;
typedef long double ld;
#define int long long
#define double ld
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<int, string> pis;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<pii> vpii;
typedef vector<char> vc;

template<class T>
void show(const vector<T> &a)
{
	for (T x : a)
		cout << x << " ";
	cout << endl;
}

const int sze = 3e5 + 50, oo = 1e18 + 500, mod = 1e9 + 7;
const double eps = 1e-9, PI = 2 * acos(0.0);
vi vertices[sze];
vi visit(sze, 0);
vc used(sze, false);
vi arr(sze, 0);
int n, m, k;
int A, B;
int cnt = 0;

int dp[10010][110];
int dpe[10010][110][2];


signed main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	/*freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);*/

	string s;
	cin >> s >> m;
	n = SZ(s);

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i % m] ++;
	}

	for (int i = 2; i < n; i++)
	{
	for (int j = 0; j < m; j++)
	{
	for (int z = 0; z <= 9; z++)
	{
		int y = (j + z) % m;
		dp[i][y] = (dp[i - 1][j] + dp[i][y]);
		if (dp[i][y] >= mod)
			dp[i][y] -= mod;
	}
	}
	}

	int ans = 0;
	for (int i = 1; i < n; i++)
	{
		ans = (ans + dp[i][0]);
		if (ans >= mod)
			ans -= mod;
	}

	for (int i = 1; i < s[0] - '0'; i++)
	{
		dpe[0][i % m][0]++;
	}
	dpe[0][(s[0] - '0') % m][1]++;

	for (int i = 1; i < n; i++)
	{
	for (int z = 0; z < m; z++)
	{
		for (int a = 0; a < s[i] - '0'; a++)
		{
			int y = (z + a) % m;
			dpe[i][y][0] = (dpe[i][y][0] + dpe[i - 1][z][1]);
			if (dpe[i][y][0] >= mod)
				dpe[i][y][0] -= mod;
		}

		for (int a = 0; a <= 9; a++)
		{
			int y = (z + a) % m;
			dpe[i][y][0] = (dpe[i][y][0] + dpe[i - 1][z][0]);
			if (dpe[i][y][0] >= mod)
				dpe[i][y][0] -= mod;
		}

		int x = s[i] - '0';
		int y = (z + x) % m;
		dpe[i][y][1] = (dpe[i][y][1] + dpe[i - 1][z][1]);
		if (dpe[i][y][1] >= mod)
			dpe[i][y][1] -= mod;
	}
	}

	for (int b = 0; b < 2; b++)
	{
		ans = (ans + dpe[n - 1][0][b]);
		if (ans >= mod)
			ans -= mod;
	}

	cout << ans;
	return 0;
}