#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void init();
void solve();

#define rep(i, a) for (int i = 0; i < (int) (a); i++)
#define reps(i, a, b) for (int i = (int) (a); i < (int) (b); i++)
#define rrep(i, a) for (int i = (int) a-1; i >= 0; i--)
#define rreps(i, a, b) for (int i = (int) (a)-1; i >= (int) (b); i--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
#define PRINT(f) if((f)){cout << (TRUE__) << endl;}else{cout << FALSE__ << endl;}
#define TRUE__  "Yes"
#define FALSE__ "No"
#define PERM(v) next_permutation(all(v))
#define UNIQUE(v) sort(all(v));(v).erase(unique(all(v)), v.end())
#define CIN(type, x) type x;cin >> x

#ifdef LOCAL
#define lcout(a) cout << a
#define lcoutln(a) cout << a << endl
#define lcerr(a) cerr << a
#define lcerrln(a) cerr << a << endl
#else
#define lcout(a) 
#define lcoutln(a) 
#define lcerr(a) 
#define lcerrln(a) 
#endif
#define MOD 1000000007
#define PI 3.141592653589793238462643383

signed main()
{
	init();
	solve();
}

int H, W;
vector<vector<bool> > v;

void init()
{
	cin >> H >> W;
	v.resize(H+2);
	rep(i, H+2) {
		v[i].resize(W+2, false);
	}
	rep(i, H) rep(j, W) {
		char c;
		cin >> c;
		v[i+1][j+1] = c == '#';
	}
}

bool walk(int& r, int& c)
{
	v[r][c] = false;
	if (v[r+1][c]) {
		r++;
		return true;
	}
	if (v[r][c+1]) {
		c++;
		return true;
	}
	return false;
}

void solve()
{
	int r = 1, c = 1;
	while (walk(r, c));
	rep(i, H) rep(j, W) {
		if (v[i+1][j+1]) {
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << "Possible" << endl;
	
}

