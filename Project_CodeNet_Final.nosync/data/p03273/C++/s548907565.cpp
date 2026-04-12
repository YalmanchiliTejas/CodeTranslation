#include <iostream>
#include <string>
#include <algorithm>
#include <utility> 
#include <unordered_set>
#include <vector>
#include <list> 
#include <string>
#include <iterator> 
#include <deque>
#include <array>
#include <forward_list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <bitset>
#include <numeric>
using namespace std;


const long double PI = 3.14159265358979323846264338327950;
const double EPS = 1e-9;
const int N = 100;

template <class T> T gcd(T a, T b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

template <class T> bool isPrime(T x) {
	for (T d = 2; d * d <= x; d++) { if (x % d == 0) return false; }
	return true;
}

bool r[N], c[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;

	cin >> n >> m;
	vector<string> g(n);

	for (int i = 0; i < n; ++i) {
		cin >> g[i];
	}

	for (int i = 0; i < n; ++i) {
		int rflag = true;
		for (int j = 0; j < m; ++j) {
			rflag = rflag && (g[i][j] == '.');
		}
		r[i] = rflag;
	}

	for (int i = 0; i < m; ++i) {
		int cflag = true;
		for (int j = 0; j < n; ++j) {
			cflag = cflag && (g[j][i] == '.');
		}
		c[i] = cflag;
	}


	for (int i = 0; i < n; ++i) {
		if (!r[i]) {
			for (int j = 0; j < m; ++j) {
				if (!c[j]) cout << g[i][j];
			}
			cout << '\n';
		}

	}

}