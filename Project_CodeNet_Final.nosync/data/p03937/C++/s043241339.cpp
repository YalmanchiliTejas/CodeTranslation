#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mid ((x + y) / 2)
#define left (ind * 2)
#define right (ind * 2 + 1)
#define mp make_pair
#define timer ((double)clock() / CLOCKS_PER_SEC)
#define endl "\n"
#define spc " "
#define d1(x) cerr<<#x<<":"<<x<<endl
#define d2(x, y) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<endl
#define d3(x, y, z) cerr<<#x<<":"<<x<<" "<<#y<<":"<<y<<" "<<#z<<":"<<z<<endl
#define fast_io() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<double, double> dd;

const int N = (int)(1e3 + 5);
const int LOG = (int)(20);

int n, m;
char s[N][N], mark[N][N];

void f(int x, int y) {
	if(x == n && y == m) {
		bool fl = false;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				if(s[i][j] != mark[i][j]) {
					fl = true;
					break;
				}
		if(!fl) {
			cout << "Possible";
			exit(0);
		}
		return;
	}
	if(x + 1 <= n) {
		mark[x + 1][y] = '#';
		f(x + 1, y);
		mark[x + 1][y] = '.';
	}
	if(y + 1 <= m) {
		mark[x][y + 1] = '#';
		f(x, y + 1);
		mark[x][y + 1] = '.';
	}
}

int main() {
	fast_io();
	// freopen("inp.in", "r", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i] + 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			mark[i][j] = '.';
	mark[1][1] = '#';
	f(1, 1);
	cout << "Impossible";
}