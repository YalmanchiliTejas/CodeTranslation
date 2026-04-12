#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<ctype.h>
#include<stdio.h>
#include<set>
#include<vector>
#include<map>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<numeric>
#include<string>
using namespace std;
typedef long long ll;
ll dx[] = { 1,1,0,-1,-1,-1,0,1 };
ll dy[] = { 0,1,1,1,0,-1,-1,-1 };
ll prime(ll x) {
	ll i;
	if (x < 2)return 0;
	else if (x == 2) return 1;
	if (x % 2 == 0) return 0;
	for (i = 3; i*i <= x; i += 2) {
		if (x%i == 0) return 0;
	}
	return 1;
}
ll gcd(ll a, ll b) {
	if (a<b) { return gcd(b, a); }
	else if (a%b) { return gcd(b, a%b); }
	else { return b; }
}

ll MOD = 1000000007;
int main() {
	ll H, W;
	cin >> H >> W;
	ll cnt = 0;
	char c[10][10];
	for (ll i = 0; i < H; i++) {
		for (ll j = 0; j < W; j++) {
			cin >> c[i][j];
			if (c[i][j] == '#')
				cnt++;
		}
	}
	if (H + W - 1 == cnt)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
}
