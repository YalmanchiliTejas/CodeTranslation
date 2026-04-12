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
#define inf 10000000000000007
#define vsort(vec) sort(vec.begin(),vec.end())
#define vreverse(vec) reverse(vec.begin(),vec.end())
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

int h, w;
char c[100][100];
bool ta[100], mu[100], a, b;

signed main() {
	cin >> h >> w;
	rep(i, h) {
		a = true;
		rep(j, w) {
			cin >> c[i][j];
			if (c[i][j] == '#')a = false;
		}
		if (a)ta[i] = true;
	}
	rep(i, w) {
		b = true;
		rep(j, h) {
			if (c[j][i] == '#')b = false;
		}
		if (b)mu[i] = true;
	}
	rep(i, h) {
		if (ta[i] == false) {
			rep(j, w) {
				if (mu[j] == false)cout << c[i][j];
			}
			cout << endl;
		}
	}
	ggr
}