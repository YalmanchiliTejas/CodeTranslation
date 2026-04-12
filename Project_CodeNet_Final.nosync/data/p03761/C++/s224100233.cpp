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

int main() {
	int n, table[50][26], m;
	char str[50][51];
	char ans[51] = {0};
	scanf("%d", &n);
	rep(i, 0, n) {
		scanf("%s", str[i]);
		rep(i2, 0, 26)table[i][i2] = 0;
		rep(i2, 0, strlen(str[i])) {
			table[i][str[i][i2] - 'a']++;
		}
	}
	rep(i, 0, 26) {
		m = 100;
		rep(i2, 0, n)m = min(table[i2][i], m);
		rep(i2, 0, m)sprintf(ans, "%s%c", ans, i + 'a');
	}
	puts(ans);
	return 0;
}
