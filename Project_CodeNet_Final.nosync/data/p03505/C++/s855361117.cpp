#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
using namespace std;

#define INF LLONG_MAX/3
#define inf INT_MAX/3
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
typedef pair<int, int> P;
typedef long long ll;

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a%b);
}
int lcm(int a, int b) {
	return a / gcd(a, b)*b;
}
int modpow(int a, int b) {
	if (b == 0)return 1;
	if (b == 1)return a % MOD;
	if (b % 2)return modpow(a, b - 1)*a%MOD;
	else return modpow(a, b / 2)*modpow(a, b / 2) % MOD;
}
int comb(int a, int b) {
	if (b == 0 || a == b)return 1;
	if (b == 1)return a % MOD;
	return (comb(a - 1, b - 1) + comb(a - 1, b)) % MOD;
}

ll k, a, b;

int main() {
	cin >> k >> a >> b;
	if (k <= a)puts("1");
	else if (a <= b)puts("-1");
	else if ((k - a) % (a - b) == 0)cout << (k - a) / (a - b) * 2 + 1 << endl;
	else cout << (k - a) / (a - b) * 2 + 3 << endl;
	return 0;
}