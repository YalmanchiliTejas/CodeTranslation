#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
#define pff(a,b) printf("%d  %d\n",a,b);
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int h, w;
	cin >> h >> w;
	char a[101][101];
	rep(i, h)rep(j, w) a[i][j] = '*';
	rep(i, h)rep(j, w) cin >> a[i][j];

	rep(i, h) {
		bool ok = true;
		rep(j, w) {
			if (a[i][j] == '#') ok = false;
		}
		if (ok) {
			rep(j, w) {
				a[i][j] = '*';
			}
		}
	}
	
	rep(j, w) {
		bool ok = true;
		rep(i, h) {
			if (a[i][j] == '#') ok = false;
		}
		if (ok)rep(i, h) a[i][j] = '*';
	}

	rep(i, h) {
		bool ok = false;
		rep(j, w) {
			if (a[i][j] != '*') {
				cout << a[i][j];
				ok = true;
			}
		}
		if (ok) cout << endl;
	}

	return 0;
}