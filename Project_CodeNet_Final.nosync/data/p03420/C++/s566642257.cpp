#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	int res = 0;
	for (int b = K + 1; b <= N; b++) {
		int aa = (N / b) + 1;
		
		res += aa*(b - K);
		res -= min(b - K, (aa*b - N - 1));
		//cerr << b << " " << res << endl;
	}
	if (K == 0) {
		res -= N - K;
	}
	cout << res << endl;
}