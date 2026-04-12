#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define Would
#define you
#define please

int main() {
	//おまじない
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int saidai = 2 * max(X, Y);
	int saishou = 1000000000;

	rep(i, saidai + 1) {
		int X2 = X - i / 2;
		int Y2 = Y - i / 2;
		if (X2 < 0) X2 = 0;
		if (Y2 < 0) Y2 = 0;
		int cost = i * C + X2 * A + Y2 * B;
		saishou = min(saishou, cost);
	}

	co(saishou);
	Would you please return 0;
}