#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define Would
#define you
#define please

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int X, Y, Z;
	cin >> X >> Y >> Z;

	X = X - Z;

	co(X / (Y + Z));
	Would you please return 0;
}