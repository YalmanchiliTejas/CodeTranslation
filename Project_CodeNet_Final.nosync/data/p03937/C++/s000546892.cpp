/* @ by batr (T) */
#include <bits/stdc++.h>
 
#define ll long long
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(), (X).end()
 
#define cmp_all(X) (X).begin(), (X).end(), cmp
 
#define B begin()
#define E end()
#define sz size()
#define skip continue
 
#define ppi pair<pair<int, int>, int>
#define pii pair<int, int> 
#define pli pair<ll, int>
#define pcc pair<char, char>
 
#define F first
#define S second
 
using namespace std;
 
const int maxn = 1e7 + 17;
const int MAXN = maxn * 4;
const int darr = 1e3 + 17;
const ll INF = 1e17 + 5;
const int mod = 1e9 + 7;
 
void Need_For_Speed () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, m;
char c[darr][darr];

int main () {
	Need_For_Speed();
	cin >> n >> m;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++) {
			c[i][j] = '.';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (c[i][j] == '#' && c[i-1][j+1] == '#') {
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << "Possible";
	return 0;
}