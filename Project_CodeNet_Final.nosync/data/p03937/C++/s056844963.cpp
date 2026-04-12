#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define INF 10000000000000007
#define ggr getchar(); getchar();return 0;
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) {
		if (x%i == 0)return false;
	}
	return true;
}

int h, w, ta;
char a[10][10];

signed main() {
	cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
			if (a[i][j] == '#')ta++;
		}
	}
	if (ta == h + w - 1)cout << "Possible" << endl;
	else cout << "Impossible" << endl;
	ggr
}