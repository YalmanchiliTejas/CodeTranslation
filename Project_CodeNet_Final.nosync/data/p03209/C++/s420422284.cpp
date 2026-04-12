#include <bits/stdc++.h>
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nyan "(=^･ω･^=)"
#define mkp make_pair
#define lP pair<ll, ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;

int N;
ll X, a[51], p[51], ans;

int main() {
	cin >> N >> X;
	a[0] = p[0] = 1;
	for (int i = 1; i != N + 1; ++i) {
		a[i] = a[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}
	int i = N;
	while (X) {
		if (X >= a[i]) {
			X -= a[i];
			ans += p[i];
		}
		else {
			if (X >= a[i - 1] + 2) {
				X -= a[i - 1] + 2;
				ans += p[i - 1] + 1;
			}
			else
				--X;
			--i;
		}
	}
	cout << ans << endl;
	return 0;
}