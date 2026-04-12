#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<tuple>
#include<algorithm>
#include<numeric>
#include<math.h>

#define REPS(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

const int mod = 1e9 + 7;
const long double pi = 3.141592653589793238462643383279502884197;
const long double eps = 1e-7;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	ll ans = 0;
	if ((A + B ) < 2 * C) {
		ans += (A*X + B*Y);
	}
	else {
		int same_num = min(X, Y);
		ans += same_num * 2 * C;
		X -= same_num;
		Y -= same_num;

		if (X > 0) {
			if (A > 2*C) {
				ans += X*C*2;
			}
			else {
				ans += X*A;
			}
		}
		else if (Y > 0) {
			if (B > 2*C) {
				ans += Y*C*2;
			}
			else {
				ans += Y*B;
			}
		}

	}
	cout << ans;
	system("pause");
	return 0;
}