#include <bits/stdc++.h>
#define INF 2147483647
#define INF_LL 9223372036854775807
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	ll N, X;
	cin >> N >> X;
	vector<ll> a(51), b(51); //a レベルnバーガーの大きさ bレベルnバーガーに含まれるパティ
	a[0] = 1; b[0] = 1;
	for (int i = 0; i < 50; i++) {
		a[i + 1] = a[i] * 2 + 3;
		b[i + 1] = b[i] * 2 + 1;
	}

	ll ans = 0;
	int i = N;
	while (X >= 0) {
		for (i ; i >= 0; i--) {
			if (X >= a[i]) {
				if (X == a[i]) {
					X -= a[i];
					ans += b[i];
				}
				else {
					X -= a[i] + 1;
					ans += b[i] + 1;
				}
				break;
			}
			X--;
			if (X == 0)break;
		}
	}
	cout << ans << endl;
	return 0;
}