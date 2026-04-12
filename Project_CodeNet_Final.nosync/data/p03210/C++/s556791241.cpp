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

int N, K;
vector<int> a;

int main() {
	cin >> N;
	if (N == 3 || N == 5 || N == 7) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;

	}
	return 0;
}
