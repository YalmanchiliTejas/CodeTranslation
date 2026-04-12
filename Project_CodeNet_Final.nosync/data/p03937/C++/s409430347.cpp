#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const int inf = (int)1e9;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 600500;

char a[1010][1010];
int n, x, y, m;
bool was[1010][1010];     

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
		cin >> a[i][j];
	
	x = 1; y = 1;
	was[1][1] = true;
	while (true)
	{
	
		if (a[x][y + 1] == '#')
		{
			was[x][y + 1] = true;
			y++;
		}
		else if (a[x + 1][y] == '#')
		{
			was[x + 1][y] = true;
			x++;
		}
		else
			break;  

	}
                     /*
	for (int i = 1; i <= n; i++) {
	for (int j = 1; j <= m; j++)
		cout << was[i][j] << ' ';
    	cout << endl;
    }                 */
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= m; j++)
	    if (a[i][j] == '#' && !was[i][j])
	    {
	    	cout << "Impossible\n";
	    	return 0;	    
	    }

	cout << "Possible\n";		
	
	return 0;
}
