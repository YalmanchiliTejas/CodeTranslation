#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
typedef long long ll;
using namespace std;

int main() {
	int H, W; cin >> H >> W;
    char S[101][101];
	int A[101];
	int B[101];
	rep(i,101){
		A[i] = 0;
		B[i] = 0;
	}
	rep(i,H){
		rep(j,W){
			cin >> S[i][j];
			if (S[i][j] == '#') {
				A[i] = 1;
				B[j] = 1;
			}
		}
	}
	rep(i,H){
		if (A[i]) {
			rep(j,W){
				if (B[j]) cout << S[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}