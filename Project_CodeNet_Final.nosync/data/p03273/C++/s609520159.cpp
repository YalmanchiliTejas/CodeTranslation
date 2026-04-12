#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000000;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

///////////////////////////




int main() {

	ll H, W;
	cin >> H >> W;

	char a[200][200];

	repn(i, H) repn(j, W) cin >> a[i][j];

	ll c[200] = {};

	repn(i, H) {


		repn(j, W) {
			if (a[i][j] == '.') { c[i]++; }
		}

		if(c[i]==W){
			repn(j, W) a[i][j] = 'x';
		}
	}

	repn(j, W) {

		ll ch = 0;

		repn(i, H) {
			if (a[i][j] == '.' || a[i][j] == 'x') { ch++; }
		}

		if (ch == H) {
			repn(i, H) a[i][j] = 'x';
		}
	}

	repn(i, H) {

		if (c[i] != W) {
			repn(j, W) {
				if (a[i][j] != 'x') { cout << a[i][j]; }
			}

			cout << endl;
		}
	}

	system("PAUSE");
}