#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const int INF = 1001001001;
//const ll INF = 1000000000000000000;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if (X > Y) {
		int Z = X;
		X = Y;
		Y = Z;
		int C = A;
		A = B;
		B = C;
	}
	int ans = INF;
	for (int c = 0; c <= 2*Y; c+=2) {
		int tmp = C*c; // tmp: total cost
		if (c/2 <= X) {
			tmp += (X - c/2)*(A + B);
			tmp += (Y - X)*B;
		}
		else {
			tmp += (Y - c/2)*B;
		}
		ans = min(ans,tmp);
	}
	cout << ans << endl;
	return 0;
} 