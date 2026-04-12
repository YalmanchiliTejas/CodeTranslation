#include <algorithm>
#include <cmath>
#include <ctype.h>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define ENDL '\n'
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FOR_EACH(i, v) for (auto&& i : v)

int N;
int M;
int ans = 0;
bool* used;

/* 無向辺クラス。自己ループあり。二重辺、重みなし。*/
class MySide {
public:
	bool* mSide;
	int mNConst;

	MySide(int n, bool initial)
	{
		int t = n * (n + 1) / 2;
		mSide = new bool[t];
		for (int i = 0; i < t; i++) {
			mSide[i] = initial;
		}
		mNConst = 2 * n - 1;
	}

	~MySide()
	{
		delete[] mSide;
	}

	int coordToI(int x, int y)
	{
		return (x * (mNConst - x) + 2 * y) / 2;
	}

	void set(int x, int y, bool value)
	{
		if (y < x) {
			swap(x, y);
		}
		mSide[coordToI(x, y)] = value;
	}

	bool get(int x, int y)
	{
		if (y < x) {
			swap(x, y);
		}
		return mSide[coordToI(x, y)];
	}
};

MySide* side;

void calc(int pos, int count)
{
	if (count == N) {
		ans++;
		return;
	}

	for (int i = 1; i < N; i++) {
		if (!used[i] && side->get(pos, i)) {
			used[i] = true;
			calc(i, count + 1);
			used[i] = false;
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	side = new MySide(N, false);
	used = new bool[N];
	FOR(i, N) {
		used[i] = false;
	}
	FOR(i, M) {
		int a;
		int b;
		cin >> a >> b;
		side->set(a - 1, b - 1, true);
	}

	used[0] = true;
	calc(0, 1);

	cout << ans << ENDL;

	delete side;
	delete[] used;
	return 0;
}