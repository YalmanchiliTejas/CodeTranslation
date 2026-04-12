#include <cmath>
#include <cassert>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define forsn(i,s,n) for (int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for (int i = (n-1);i >= (int)(s);i--)
#define dforn(i,n) dforsn(i,0,n)
#define all(v) (v).begin(), (v).end()
#define F first
#define S second

typedef long long int tint;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	tint n, k; cin >> n >> k;

	tint res = 0;
	forsn(i, k + 1, n + 1) {
		for (int j = 0;j <= n;j += i) {
			res += max(0LL, min(i - k, n - j + 1 - k));
		}
		res -= k == 0;
	}
	
	cout << res << endl;
}
