#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<cmath>
#include<deque>
#include<set>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define INF 1LL << 60
#define MAX 1000000000

const double PI = 3.14159265358979323846;
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll power(ll x, ll p) { ll a = 1; while (p > 0) { if (p % 2 == 0) { x *= x; p /= 2; } else { a *= x; p--; } }return a; }

char m[10][10];
int main() {
	int W, H, x = 0, y = 0;
	scanf("%d%d", &H, &W);
	rep(i, 0, H)scanf("%s", m[i]);
	m[0][0] = '.';
	while (1) {
		if (m[x][y + 1] == '#')m[x][y + 1] = '.', y++;
		else if (m[x + 1][y] == '#')m[x + 1][y] = '.', x++;
		else break;
		if (x == H - 1 && y == W - 1)break;
	}
	rep(i, 0, H)rep(i2, 0, W)if (m[i][i2] == '#') { puts("Impossible"); return 0; }
	puts("Possible");
	return 0;
}
