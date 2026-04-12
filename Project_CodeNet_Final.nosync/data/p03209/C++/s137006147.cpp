#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>
#define ALL(c) (c).begin(), (c).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pdi = pair<double, int>;

int N;
ll X;
ll nlayer[51];
ll nP[51];

ll npatty(int n, ll x) {
	if (n >= 1)
		if (x == 1) {
			return 0;
		}
		else if (x <= 1 + nlayer[n - 1]) {
			return npatty(n - 1, x - 1);
		}
		else if (x == 1 + nlayer[n - 1] + 1) {
			return npatty(n - 1, x - 1) + 1;
		}
		else if (x <= 1 + nlayer[n - 1] + 1 + nlayer[n - 1]) {
			return nP[n - 1] + 1 + npatty(n - 1, x - (1 + nlayer[n - 1] + 1));
		}
		else {
			return nP[n - 1] * 2 + 1;
		}
	else
		return 1;
}

int main() {
	cin >> N >> X;
	for (int i = 0; i <= N; i++)
	{
		nlayer[i] = pow(2, i + 2) - 3;
		nP[i] = pow(2, i + 1) - 1;
	}
	cout << npatty(N, X) << endl;
	return 0;
}

