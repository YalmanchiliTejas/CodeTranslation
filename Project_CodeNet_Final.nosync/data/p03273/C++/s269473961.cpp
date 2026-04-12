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
#define rep(i,rept)	for(ll i = 0; i<rept;i++)
typedef long long ll;
using namespace std;

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
	int h = 0, w = 0;
	int count = 0;
	char map[100][100] = {};
	int tate[100] = {}, yoko[100] = {};
	std::cin >> h >> w;
	rep(i, h) {
		rep(j, w) {
			std::cin >> map[i][j];
			if (map[i][j] == '.') {
				tate[i]++;
				yoko[j]++;
			}
		}
	}
	rep(i, h) {
		rep(j, w) {
			if (tate[i] != w && yoko[j] != h) {
				std::cout << map[i][j];
				count++;
			}
		}
		if (count != 0) {
			std::cout << std::endl;
		}
		count = 0;
	}

	return 0;
}