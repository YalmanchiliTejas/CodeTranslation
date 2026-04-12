#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int H, W;
	cin >> H >> W;

	string A[8];
	rep(i, H) cin >> A[i];

	int OK = 1;
	rep(i, H) rep(j, W) {
		if (i == 0 && j == 0) {
			int ato = 0;
			if (A[i + 1][j] == '#') ato++;
			if (A[i][j + 1] == '#') ato++;
			if (ato != 1) OK = 0;
		}
		else if (i == H - 1 && j == W - 1) {
			int mae = 0;
			if (A[i - 1][j] == '#') mae++;
			if (A[i][j - 1] == '#') mae++;
			if (mae != 1) OK = 0;
		}
		else if (A[i][j] == '#') {
			int mae = 0;
			if (i != 0) if (A[i - 1][j] == '#') mae++;
			if (j != 0) if (A[i][j - 1] == '#') mae++;
			if (mae != 1) OK = 0;
			int ato = 0;
			if (i != H - 1) if (A[i + 1][j] == '#') ato++;
			if (j != W - 1) if (A[i][j + 1] == '#') ato++;
			if (ato != 1) OK = 0;
		}
	}

	if (OK) co("Possible");
	else co("Impossible");

	Would you please return 0;
}