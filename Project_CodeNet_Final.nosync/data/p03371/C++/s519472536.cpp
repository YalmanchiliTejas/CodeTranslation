#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <tuple>

#include <set>
#include <unordered_map>
#include <stack>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
template<class T>bool chmaxj(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
void YesNo(bool y) { cout << (y ? "Yes" : "No") << endl; } //true==yes


#define INF 21474836

//////////////////////////////////////////////////////////////


int main() {

	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	long long ans = 0;
	if (A + B < C * 2) {
		ans = A * X + B * Y;
	}
	else {
		if (A > C * 2) {
			ans = X * (C * 2);
			if (B > C * 2) {
				if (Y > X)ans += (Y - X) * (C * 2);
			}
			else {
				if (Y > X)ans += (Y - X) * B;
			}
		}
		else if (B > C * 2) {
			ans = Y * (C * 2);
			if (X > Y)ans += (X - Y) * A;	
		}
		else {
			if (X > Y) {
				ans = Y * (C * 2) + (X - Y) * A;
			}
			else {
				ans = X * (C * 2) + (Y - X) * B;
			}
		}
	}

	cout << ans << endl;

	return 0;
}