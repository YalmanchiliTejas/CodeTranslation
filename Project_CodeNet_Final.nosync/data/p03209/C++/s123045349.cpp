#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

vector<long long int> v(1, 1), p(1, 1);

long long int f(long long int layer, long long int x) {
	if (x == 0) return 0;
	if (x == 1) {
		if (layer == 0) return 1;
		return 0;
	}

	if (x <= v[layer - 1] + 1) {
		return f(layer - 1, x - 1);
	} else {
		return p[layer - 1] + 1 + f(layer - 1, min(x - 2 - v[layer - 1], v[layer - 1]));
	}
}

int main() {
    long long int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
    	v.push_back(2 * v.back() + 3);	
    	p.push_back(2 * p.back() + 1);
    }
    cout << f(n, x) << endl;
}
