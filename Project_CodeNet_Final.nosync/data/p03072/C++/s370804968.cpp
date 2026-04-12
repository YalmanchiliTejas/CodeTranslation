#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<functional>
#include<map>
#include<cstdlib>
#include<complex>
#include<numeric>
#include<set>
#include<deque>
#include<queue>

using namespace std;
using Int = long long;
Int INF = 1LL << 60;
const Int MOD = 1000000000 + 7;

int main() {

	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	Int N;
	cin >> N;

	vector<Int> h(N);
	for (Int i = 0; i < N; i++) {
		cin >> h[i];
	}

	vector<Int> high(N);
	high[0] = h[0];
	Int ans = 1;
	for (Int i = 0; i < N-1; i++) {
		if (h[i + 1] >= high[i]) {
			ans++;
			high[i + 1] = h[i + 1];
		}
		else {
			high[i + 1] = high[i];
		}
	}
	cout << ans << "\n";
}
