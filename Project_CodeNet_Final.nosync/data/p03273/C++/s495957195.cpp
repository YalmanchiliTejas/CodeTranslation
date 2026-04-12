#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
// #include <numeric>
#include <complex>

#define FAST ios_base::sync_with_stdio(false); cin.tie(0)
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define repr(i, a, b) for(int i=int(a); i>=int(b); i--)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
typedef long long int ll;
#define iceil(x,y) (x+y-1)/y

using namespace std;
typedef pair<int, int> PII;

int main() {
	FAST;

	int h, w;
	cin >> h >> w;
	char a[h][w];
	int f[h][w];
	rep(i,h) {
		rep(j,w) {
			cin >> a[i][j];
			if (a[i][j] == '#') f[i][j] = 1;
			else f[i][j] = 0;
		}
	}

	int pr[h] = {};
	int pc[w] = {};
	rep(i,h) {
		rep(j,w) {
			pr[i] += f[i][j];
			pc[j] += f[i][j];
		}
	}

	rep(i,h) {
		rep(j,w) {
			if ((pr[i] != 0) && (pc[j] != 0)) {
				cout << a[i][j];
			}
		}
		if (pr[i] != 0) cout << "\n";
	}

	return 0;
}