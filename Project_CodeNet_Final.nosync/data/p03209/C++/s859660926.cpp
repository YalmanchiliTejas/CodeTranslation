#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
int n;
ll x;
ll num[55], numP[55];

ll rec(int layer, ll i) {
	if (i == 0) return 0;
	ll mid = num[layer] / 2l;
	if (i == num[layer]) return numP[layer];
	if (i > mid) {
		return numP[layer-1] + rec(layer-1, i-mid-1) + 1l;
	} else if (i == mid) {
		return numP[layer-1];
	} else if (i < mid) {
		return rec(layer-1, i - 1);
	}
}

int main() {
	cin >> n >> x;
	num[0] = 1;
	numP[0] = 1;
	for (int i = 1; i <= 50; i++) {
		num[i] = 3l + 2l*num[i-1];
		numP[i] = 2l * numP[i-1] + 1;
	}
	ll ans = rec(n, x);
	cout << ans << endl;
}