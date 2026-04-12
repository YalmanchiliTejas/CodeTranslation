#include <bits/stdc++.h>
using namespace std;

void solve(long long H, long long W, vector<string> A){
	vector<int> L(H, W), R(H, 0);
	for(int i = 0; i < H; ++i) {
		for(int j = 0; j < W; ++j) {
			if(A[i][j] == '#') {
				L[i] = min(L[i], j);
				R[i] = max(R[i], j);
			}
		}
	}
	for(int i = 1; i < H; ++i) {
		int cnt = 0;
		for(int j = 0; j < W; ++j) {
			if(A[i-1][j] == '#' && A[i][j] == '#') {
				++cnt;
			}
		}
		if(L[i-1] > L[i] || R[i-1] > R[i] || cnt > 1) {
			cout << "Impossible" << endl;
			return;
		}
	}
	cout << "Possible" << endl;
}

int main(){	
	long long W;
	long long H;
	scanf("%lld",&H);
	vector<string> A(H-1+1);
	scanf("%lld",&W);
	for(int i = 0 ; i <= H-1 ; i++){
		cin >> A[i];
	}
	solve(H, W, A);
	return 0;
}

