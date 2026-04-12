#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<utility>
#include<stack>
#include<queue>
#include<cmath>
#include<list>
#include<cstdint>
#include<vector>
#include<map>
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i,rept)	for(ll i = 0; i<rept;i++)
typedef long long ll;

ll nCr(ll n, ll r) {
	if (r > n) { return 0; }
	if (r * 2 > n) r = n - r;
	ll dividend = 1;
	ll divisor = 1;
	for (ll i = 1; i <= r; ++i) {
		dividend *= (n - i + 1);
		divisor *= i;
	}
	return dividend / divisor;
}
ll sumdigit(ll n) {
	ll dig = 0, sum = 0;
	while (n) {
		dig = n % 10;
		sum = sum + dig;
		n = n / 10;
	}
	return sum;
}



int main() {
	std::string a, b, c, d;
	std::cin >> a >> b >> c;
	d = a + b + c;
	int e;
	e = std::stoi(d);
	if (e % 4 == 0) {
		std::cout << "YES" << std::endl;
	}
	else {
		std::cout << "NO" << std::endl;
	}
}