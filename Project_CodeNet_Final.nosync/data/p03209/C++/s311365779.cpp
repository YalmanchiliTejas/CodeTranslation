#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cassert>

#define rep(j, n) for (int i = j; i < n; i++)
#define repd(j, n) for (int i = j; i > n; i--)

using namespace std;
typedef long long int ll;
typedef pair <int, int> P;

ll burg(ll x, ll y) {
	vector<ll> a(x + 1), b(x + 1);
	a[0] = 1;
	b[0] = 1;
	rep(1, x + 1) {
		a[i] = 2 * a[i - 1] + 3;
		b[i] = 2 * b[i - 1] + 1;
	}
	if (x==0) {
		if (y == 0) { return 0; }
		else {
			return 1;
		}
	}
	if (y == 1) {
		return 0;
	}
	if (y > 1 && y <= a[x - 1] + 1) {
		return burg(x - 1, y - 1);
	}
	if (y ==a[x - 1] + 2) {
		return b[x - 1] + 1;
	}
	if (y > 2 + a[x - 1] && y <= 2 * a[x - 1] + 2) {
		return b[x - 1] + 1 + burg(x - 1, y - 2 - a[x - 1]);
	}
	 if(y==2*a[x-1]+3) {
		 return 2 * b[x - 1] + 1;
	}
}

int main() {
	ll n, k;
	cin>>n>>k;
	cout << burg(n,k) << endl;
	return 0;
}