#include <bits/stdc++.h>

using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VL = vector<long long>;
using VVL = vector<VL>;

#define sz(var) (int)var.size()
#define REP(var, start, end) for(int var = start; var < (int)end; ++var)
#define CLEAR(var, with) memset(var, with, sizeof(var))
#define ALL(x) x.begin(), x.end()
#define LL long long
#define ULL unsigned long long


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("tmp.in", "r", stdin);
//	freopen("tmp.out", "w", stderr);
#endif
    int r, g, b;
	cin >> r >> g >> b;

	r *= 100; g *= 10;
	r += g + b;

	if(r % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}