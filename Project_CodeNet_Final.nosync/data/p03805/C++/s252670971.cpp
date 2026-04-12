#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <deque>
#include <queue>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <set>
#define INF 1000000000000
using namespace std;
using ll = long long;
int main() {
	ll n, m;
	cin >> n >> m;
	vector<ll> v(n - 1);
	bool ed[10][10] = {};
	int x = 0;
	for (ll i = 2; i <= n; i++) {
		v[x] = i;
		x++;
	}
	for (ll i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		ed[x][y] = ed[y][x] = true;
	}
	ll ans = 0;

	do {
		bool flag = false;
		for (ll i = 0; i < n-1; i++) {
			if (i == 0) {
				if (ed[v[i]][1] == false) {
					flag = true;
					break;
				}
			}else {
				if (ed[v[i]][v[i - 1]] == false) {
					flag = true;
					break;
				}
			}
		}
		if(flag==false){
			ans++;
		}
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << endl;
}