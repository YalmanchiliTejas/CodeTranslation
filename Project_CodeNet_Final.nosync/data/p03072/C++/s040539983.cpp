#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <functional>
#include <map>
using namespace std;

int N, H[10008], maxn = 0, sum = 0;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> H[i];
		if (maxn <= H[i]) { sum++; }
		maxn = max(maxn, H[i]);
	}
	cout << sum << endl;
	return 0;
}