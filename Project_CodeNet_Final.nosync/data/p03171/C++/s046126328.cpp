#include "bits/stdc++.h"
using namespace std;

long long n;
vector<long long> nms;

const long long MXN = 3005;
long long dp[MXN][MXN];

long long best(long long l, long long r) {
	if (l > r) return 0;
	if (l == r) return nms[l];
	if (l + 1 == r) {
		return max(nms[l], nms[r]) - min(nms[l], nms[r]);
	}
	if (dp[l][r] != -1) return dp[l][r];
	return dp[l][r] = max(nms[l] - best(l+1, r), nms[r] - best(l, r-1));
}

int main() {
	
	for (int i=0; i<MXN; i++) for (int j=0; j<MXN; j++) dp[i][j] = -1;
	
	cin >> n;
	for (int i=0; i<n; i++) {
		long long x;
		cin >> x;
		nms.push_back(x);
	}
	cout << best(0, n-1) << endl;
	
}


