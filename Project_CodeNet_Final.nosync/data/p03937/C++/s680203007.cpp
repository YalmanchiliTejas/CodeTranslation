#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


vector<int>  dx = {1,-1,0,0};
vector<int>  dy = {0,0,1,-1};


int main() {
	int H,W; cin >> H >> W;

	vector<string> A(H);
	for (int i = 0; i < H; i++) {
		cin >> A[i];
	}

	int cnt = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A[i][j] == '#') {
				cnt++;
			}
		}
	}

	if (H + W - 1 == cnt ) {
		cout << "Possible" << endl;
	}else {
		cout << "Impossible" << endl;
	}

	return 0;
}
