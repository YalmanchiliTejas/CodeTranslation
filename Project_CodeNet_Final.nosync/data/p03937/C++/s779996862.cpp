#include"bits/stdc++.h"

#define rep(i, N) for(int i = 0;i < N;i++)

typedef long long ll;

const int mod = 1e9 + 7;

using namespace std;



int main(void) {
	int H, W; cin >> H >> W;
	vector<string> A(H);
	rep(i, H)cin >> A[i];

	int cnt = 0;
	rep(i, H)rep(j, W) {
		cnt += (int)(A[i][j] == '#');
	}

	cout << (cnt == H + W - 1 ? "Possible" : "Impossible") << endl;

	return 0;
}