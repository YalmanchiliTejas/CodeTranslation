#include<iostream>
#include <cstdio>
#include<cstring>
#include<string>
#include <cstdlib>  
#include<cmath>   
#include <cctype>
#include<string>
#include<set>
#include <iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<list>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility>
#define LEN 100005
using namespace std;
using ll = long long;
double pi() { return 3.14; }
int sum(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
ll LGCD(ll x, ll y) { if (x % y == 0) return y;else return LGCD(y, x % y); }
ll LLCM(ll x, ll y) { return x * y / LGCD(x, y); }

int GCD(int x, int y) { if (x % y == 0) return y;else return GCD(y, x % y); }
int LCM(int x, int y) { return x * y / GCD(x, y); }
ll dpc[10000][10000];

bool chsK(string s) {
	int n = s.length();
	if (n % 2 == 0) {
		for (int i = 0;i <= n / 2;i++) {
			if (s[i] != s[n - i - 1])return false;
		}
	}
	else {
		for (int i = 0;i <= n / 2;i++) {
			if (s[i] != s[n - i - 1])return false;
		}
	}
	return true;
}

//void nCr(ll n, ll r) {
//	ll ans = 1;
//	for (int i = n; i > n - r; --i) {
//		ans = ans * i;
//	}
//	for (int i = 1; i < r + 1; ++i) {
//		ans = ans / i;
//	}
//	printf("%d",ans);
//}

ll combination(ll n, ll r) {
	if (n == r) { return dpc[n][n] = 1; }
	else if (r == 0) { return dpc[n][0] = 1; }
	else if (r == 1) { return dpc[n][1] = n; }
	else if (dpc[n][r]) { return dpc[n][r]; }
	else { return dpc[n][r] = combination(n - 1, r - 1) + combination(n - 1, r); }
}




int main() {
	ll a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	ll ans = 0;
	ll dx,dy;
	dx = x / 2;
	dy = y / 2;
	ans = a * x + y * b;
	if (a + b > 2 * c) {
		if (x > y) {
			

			ans=min(ans - y*(a + b - 2 * c),2*x*c);
		}
		else {
			
			ans = min(ans - x*(a + b - 2 * c),2*y*c);
		}
	}


	cout << ans << endl;
	return 0;
}
