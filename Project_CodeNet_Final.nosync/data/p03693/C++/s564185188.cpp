#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

int main(void) {

	ll r, g, b;
	cin >> r >> g >> b;

	ll sum = r * 100 + g * 10 + b;

	if (sum % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

	return 0;
}