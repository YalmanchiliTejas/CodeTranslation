/**
 	Template created by Danel Batyrbek
 	All rights are reserved 2017 (lol)
*/

#include <bits/stdc++.h>

#define speed_up ios_base :: sync_with_stdio(0);cin.tie(0)
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define debug(x) cerr << x << '\n';
#define YES "YES"
#define NO "NO"
#define skip continue
#define left(x) x << 1
#define rght(x) x << 1 | 1
#define forn(x, y, z) for(int x = y; x <= z; ++ x)
#define for1(x, y, z) for(int x = y; x >= z; -- x)
#define fname ""
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef double ld;

const int N = 1e5 + 10;
const int mod = 1e9 + 7;
const int N3 = 1e3 + 10;
const int INF = 2e9 + 10;
const ll LINF = 2e18;

int n, m;
char a[20][20];

bool u[20][20];

bool check(){
	forn(i, 1, n){
		forn(j, 1, m){
			if(a[i][j] == '#' && u[i][j]) skip;
			if(a[i][j] == '.' && !u[i][j]) skip;
			return 0;
		}
	}
	return 1;
}

bool dfs(int x, int y){
	if(a[x][y] == '.') return 0;
	u[x][y] = 1;
	if(x == n && y == m) return 1;
	if(a[x + 1][y] == a[x][y + 1]) return 0;
	if(a[x + 1][y] == '#') return dfs(x + 1, y);
	if(a[x][y + 1] == '#') return dfs(x, y + 1);
	return 0;
}

int main(){
#ifndef DEBUG
	if(fname != ""){
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	}
#endif	
	cin >> n >> m;
	forn(i, 1, n + 1){
		forn(j, 1, m + 1){
			a[i][j] == '.';
		}
	}
	forn(i, 1, n){
		forn(j, 1, m){
        	cin >> a[i][j];
        }
	}
	if(dfs(1, 1) && check()){
		cout << "Possible";
	} else {
		cout << "Impossible";
	}
	return 0;
}