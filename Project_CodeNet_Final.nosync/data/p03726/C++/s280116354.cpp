#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>
#include <stack>
#include <cstdlib>
#include <map>
#include <iomanip>
#include <set>
#include <stdio.h>
#include <ctype.h>
#include <random>
#include <string.h>
#include <cmath>
using namespace std;
#define pie 3.141592653589793238462643383279
#define mod 1000000007
#define int long long
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()

int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x%y);
}
int lcm(int x, int y) {
	return x / gcd(x, y)*y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}

int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}

int n;
vector<int> vec[100010];
bool bl[100010];
int cnt[100010];
queue<P> que;

signed main() {
	cin >> n;
	if (n % 2) {
		cout << "First" << endl;
		return 0;
	}
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)if ((int)vec[i].size() == 1) {
		que.push(make_pair(vec[i][0], 0));
		if (bl[vec[i][0]]) {
			cout << "First" << endl;
			return 0;
		}
		bl[vec[i][0]] = true;
	}
	while (!que.empty()) {
		int v = que.front().first, p = que.front().second; que.pop();
		for (int i = 0; i < (int)vec[v].size(); i++) {
			if ((int)vec[vec[v][i]].size() != 2)continue;
			for (int j = 0; j < 2; j++)if (v != vec[vec[v][i]][j]) {
				if (vec[vec[v][i]][j] == p)continue;
				if (bl[vec[vec[v][i]][j]]) {
					cout << "First" << endl;
					return 0;
				}
				bl[vec[vec[v][i]][j]] = true;
				que.push(make_pair(vec[vec[v][i]][j], v));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if ((int)vec[i].size() <= 2)continue;
		bool bl2 = true;
		for (int j = 0; j < (int)vec[i].size(); j++)if (!bl[vec[i][j]])bl2 = false;
		if (bl2) {
			cout << "First" << endl;
			return 0;
		}
	}
	cout << "Second" << endl;
}
