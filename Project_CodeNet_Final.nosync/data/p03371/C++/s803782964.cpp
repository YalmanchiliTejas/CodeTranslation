#include <bits/stdc++.h>
#include <unordered_map>
#define sp ' '
#define nyan "(=^・ω・^=)"
#define mkp make_pair
#define intmax 2147483647
#define llmax 9223372036854775807
#define lP pair<ll,ll>
#define iP pair<int,int>
typedef long long ll;
using namespace std;
const int mod=1000000007;


ll A, B, C, X, Y, res;

int main() {
	cin >> A >> B >> C >> X >> Y;
	if (C * 2 > A + B) {
		cout << A * X + B * Y << endl;
	}
	else {
		res += min(X, Y) * 2 * C;
		if (X > Y) {
			res += (X - Y)*min(C * 2, A);
		}
		else {
			res += (Y - X)*min(C * 2, B);
		}
		cout << res << endl;
	}
	return 0;
}