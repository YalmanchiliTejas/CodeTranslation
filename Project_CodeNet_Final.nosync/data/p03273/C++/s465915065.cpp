#include<stdio.h>
#include<iostream>
#include<string>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<ctime>
#include<functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
int main() {
	ll a, b, z[100][100] = {};
	cin >> a >> b;
	bool x;
	char c[100][100];
	for (ll i = 0; i < a; i++) {
		x = true;
		for (ll j = 0; j < b; j++) {
			cin >> c[i][j];
			if (c[i][j] != '.') x = false;
		}
		if (x) {
			for (int j = 0; j < b; j++) {
				z[i][j] = 1;
			}
		}
	}
	for (ll i = 0; i < b; i++) {
		x = true;
		for (ll j = 0; j < a; j++) {
			if (c[j][i] != '.') x = false;
		}
		if (x) {
			for (int j = 0; j < a; j++) {
				z[j][i] = 1;
			}
		}
	}
	for (ll i = 0; i < a; i++) {
		for (ll j = 0; j < b; j++) {
			if (z[i][j] != 1) cout << c[i][j];
		}
		cout << endl;
	}
	return 0;
}
