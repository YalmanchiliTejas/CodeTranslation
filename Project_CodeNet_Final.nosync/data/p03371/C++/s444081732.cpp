#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
const ll mod = ll(1e9) + 7;
const int INF = int(1e9);

int main() {
	cin.sync_with_stdio(false);
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	if (A + B <= C*2)cout << A*X + B*Y << endl;
	else {
		int sum = 0;
		int x, y;
		if (X >= Y) {
			x = X;y = Y;
		}
		else {
			x = Y; y = X;
			swap(A, B);
		}
		sum += C*y*2;
		x -= y;
		sum += min(A*x, C*x*2);
		cout << sum << endl;
	}
	return 0;
}
