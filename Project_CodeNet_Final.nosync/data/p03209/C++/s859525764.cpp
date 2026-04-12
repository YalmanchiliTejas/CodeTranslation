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
typedef long long ll;
typedef unsigned long long ull;

ull Psize[51];
ull ALLsize[51];

int main()
{
	int N, level;
	ull X, pos, ans = 0;

	Psize[0] = 1;
	ALLsize[0] = 1;

	cin >> N >> X;

	repc(i, 1, N) {
		ALLsize[i] = ALLsize[i - 1] * 2 + 3;
		Psize[i] = Psize[i - 1] * 2 + 1;
	}

	level = N;

	while (X > 0) {
		if (level == 0) {
			ans++;
			break;
		}

		pos = ALLsize[level] / 2 + 1;

		if (pos <= X) {
			ans += Psize[level - 1] + 1;
			X -= pos;
		}
		else {
			X--;
		}
		level--;
	}

	cout << ans << endl;

	return 0;
}