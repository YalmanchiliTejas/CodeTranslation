#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef int64_t lint;

int main() {
	lint N, X, M;
	cin >> N >> X >> M;
	vector<int> v(M);
	vector<int> w(M);
	v.at(X) = 1;
	w.at(0) = X;
	lint a=X, b=N-1, c=0, x, y, z;
	rep(i, N-1) {
		X *= X;
		X %= M;
		if (v.at(X) != 0) {
			if (X == 0) {
				std::cout << a << '\n';
			} else if (X == 1) {
				std::cout << a + b << '\n';
			} else {
				x = i + 2 - v.at(X);
				y = a;
				rep(j, v.at(X)-1) {
					y -= w.at(j);
				}
				a += y * (b/x);
				b %= x;
				rep(j, b) {
					a += X;
					X *= X;
					X %= M;
				}
				std::cout << a << '\n';
			}
			return 0;
		} else {
			v.at(X) = i+2;
			w.at(i+1) = X;
			a += X;
			b--;
		}
	}
	std::cout << a << '\n';
}
