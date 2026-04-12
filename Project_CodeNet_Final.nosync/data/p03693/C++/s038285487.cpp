#include "bits/stdc++.h"

using namespace std;

#define pb push_back
#define mp make_pair
constexpr int INF = 1 << 29;
constexpr int MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;

constexpr int dx[4] = {1, 0, -1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((a * 100 + b * 10 + c) % 4 == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
