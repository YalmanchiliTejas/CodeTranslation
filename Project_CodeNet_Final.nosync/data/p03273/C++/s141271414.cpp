#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <set>

#define rep(i,N) for(int (i)=0;(i)<(N);(i)++)
#define MOD 1000000007

using namespace std;

int pow_mod(int a, int b, int p) {
	if (b == 0)return 1;
	else if (b % 2 == 0)return (pow_mod(a*a, b / 2, p) % p);
	else return (pow_mod(a, b - 1, p)*a%p);
}

int factorial_mod(int a, int p) {
	if (!a)return 1;
	else return a * factorial_mod(a - 1, p) % p;
}

int sum_digit(int N) {
	int ans = 0;
	for (; N != 0;) {
		ans += N % 10;
		N /= 10;
	}
	return ans;
}

int H, W;
string a[110];
bool h[110] = { 0 }, w[110] = { 0 };

int main(){
	scanf("%d %d", &H, &W);
	rep(i, H)cin >> a[i];
	rep(i, H) {
		rep(j, W)if (a[i][j] == '#') {
			h[i] = true;
			w[j] = true;
		}
	}
	int w_max = 0;
	rep(i, W)if (w[i])w_max = max(w_max, i);
	rep(i, H) {
		if (h[i]) {
			rep(j, W) {
				if (w[j]) {
					cout << a[i][j];
					if (j == w_max)cout << "\n";
				}
			}
		}
	}
	return 0;
}