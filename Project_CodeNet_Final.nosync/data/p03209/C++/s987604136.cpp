#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

const int IINF = 2002002002;
const ll LINF = 9009009009009009009LL;

//===


Vl num, pa;



ll dfs(int level, ll pos)
{
	if (level == 0) {
		return 1;
	}

	ll res = 0;
	if (pos == 0) {
		res = 0;
	}
	else if (pos <= num[level - 1]) {
		res = dfs(level - 1, pos - 1);
	}
	else if (pos == num[level - 1] + 1) {
		res = dfs(level - 1, pos - 1) + 1;
	}
	else if (pos <= num[level - 1] * 2 + 1) {
		res = dfs(level - 1, pos - num[level - 1] - 2) + pa[level - 1] + 1;
	}
	else {
		res = pa[level];
	}

	return res;
}





int main()
{
	int N;
	ll X;
	cin >> N >> X;

	num.resize(N + 1);
	pa.resize(N + 1);

	num[0] = 1;
	pa[0] = 1;
	for (int i = 0; i < N; ++i) {
		num[i + 1] = num[i] * 2 + 3;
		pa[i + 1] = pa[i] * 2 + 1;
	}


	ll ans = dfs(N, X - 1);

	cout << ans << endl;
}