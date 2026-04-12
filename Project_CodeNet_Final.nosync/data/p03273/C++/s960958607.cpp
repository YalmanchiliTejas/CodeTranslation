#include <bits/stdc++.h>

using namespace std;

/********** TEMPLATE STARTS HERE ***********/

#define IOS ios::sync_with_stdio(false), cin.tie(0);
#define all(v) v.begin(), v.end()
#define F first
#define S second
#define pb push_back
#define test int t; cin >> t; while(t--)
#define skip continue
#define stop break
#define sz(v) v.size()
#define endl '\n'
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9
#define FR(i, l, r) for(int i = (l); i <= (r); i++)
#define gcd __gcd 
#define FO(i, a) for(auto & i : a)
#define debug(a) cout << #a << ": " << a << endl
#define debug1(a, l, r) FR(i, l, r) cout << a[i] << " "; cout << endl
#define SET(a, b) memset(a, b, sizeof(a));
#define refresh fflush(stdout);

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <pii> vii;
typedef vector <pll> vll;

const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;

template <typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template <typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
//template <typename T> inline void out(T x) { cout << x; }

/*********** TEMPLATE ENDS HERE *************/

bool v[103][103];
bool b[103][103];


main()
{
	int n, m;
	cin >> n >> m;
	
//	if(n == 1 || m == 1)
//		return 0;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;
			if(c == '#')
				v[i][j] = 1;
		}
	
	for(int i = 1; i <= n; i++)
	{
		if(v[i][1])
			continue;
		bool ok = true;
		for(int j = 2; j <= m && ok; j++)
			if(v[i][j] != v[i][j - 1])
				ok = false;
		if(ok == true)
			for(int j = 1; j <= m; j++)
				b[i][j] = true;
	}
	
	for(int j = 1; j <= m; j++)
	{
		if(v[1][j])
			continue;
		bool ok = true;
		for(int i = 2; i <= n && ok; i++)
			if(v[i][j] != v[i - 1][j])
				ok = false;
				
		if(ok == true)
			for(int i = 1; i <= n; i++)
				b[i][j] = true;
	}
	
	for(int i = 1; i <= n; i++)
	{
		bool ok = false;
		for(int j = 1; j <= m; j++)
			if(b[i][j] == false)
			{
				ok = true;
				if(v[i][j] == 1)
					cout << '#';
				else
					cout << '.';
			}
		if(ok == true)
			cout << endl;
	}
	
}