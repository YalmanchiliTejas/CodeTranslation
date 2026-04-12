#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>

using ll = long long;
typedef unsigned long long ull;
typedef std::pair<int, int>p;

ll min(ll a, ll b) {
	if (a >= b)return b;
	else return a;
}
ll max(ll a, ll b) {
	if (a >= b)return a;
	else return b;
}
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}

const ll Z = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
bool flag = true;
bool fl = false;
bool f = false;
bool used[210];
bool graph[100][100];
bool visited[8];
int abc[26] = { 0 };

int main() {
	int h, w;
	char c[10][10];
	bool b[10][10];
	std::cin >> h >> w;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			std::cin >> c[i][j];
			b[i][j] = false;
		}
	}
	int i = 0, j = 0;
	b[0][0] = true;
	while (i < h && j < w) {
		if (i + 1 < h&&c[i + 1][j] == '#') {
			b[i+1][j] = true;
			i++;
		}
		else if (j + 1 < w&&c[i][j + 1] == '#') {
			b[i][j + 1] = true;
			j++;
		}
		else break;
	}
	b[i][j] = true;
	for (int i = 0;i < h;i++) {
		for (int j = 0;j < w;j++) {
			if (c[i][j] == '#'&&b[i][j] == false) {
				std::cout << "Impossible" << std::endl;
				flag = false;
				break;
			}
		}
		if (flag == false)break;
	}
	if (flag)std::cout << "Possible" << std::endl;
}