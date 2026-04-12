#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

#include <cstdio>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define swap(a, b, type) { type _tmp = a; a = b; b = _tmp; }
typedef long long ll;
typedef unsigned long long ull;

int H[20];

int main()
{
	int N;
	bool ok;
	int ans = 0;

	cin >> N;
	rep(i, N) cin >> H[i];

	rep(i, N) {
		if (i == 0) {
			ans++;
			continue;
		}

		ok = true;
		rep(j, i) {
			if (H[j] > H[i]) ok = false;
		}
		if (ok) ans++;
	}

	cout << ans << endl;

	return 0;
}
