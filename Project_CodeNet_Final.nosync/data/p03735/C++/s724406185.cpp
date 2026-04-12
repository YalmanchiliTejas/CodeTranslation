#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
i64 X[202020], Y[202020];
pair<i64, int> small, large;
int sp, lp;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld%lld", X + i, Y + i);
		if (X[i] > Y[i]) swap(X[i], Y[i]);
	}

	small = make_pair(X[0], 0);
	large = make_pair(Y[0], 0);
	for (int i = 0; i < N; ++i) {
		small = min(small, { X[i], i });
		large = max(large, { Y[i], i });
	}
	sp = small.second;
	lp = large.second;

	i64 ret = 1LL << 62LL;
	if (sp != lp) {
		i64 rmax = Y[lp];
		i64 rmin = X[sp];
		i64 bmax = X[lp];
		i64 bmin = Y[sp];
		if (bmax < bmin) swap(bmax, bmin);

		vector<pair<i64, i64> > cov;
		for (int i = 0; i < N; ++i) if (i != lp && i != sp) {
			cov.push_back({ X[i], Y[i] });
		}
		sort(cov.begin(), cov.end());
		i64 w = 1001001001;
		multiset<i64> waf;
		for (auto a : cov) waf.insert(a.first);

		for (auto a : cov) {
			i64 x = a.first, y = a.second;
			w = min(w, max(bmax, *--waf.end()) - min(bmin, x));
			waf.erase(waf.find(x));
			bmax = max(bmax, y);
			bmin = min(bmin, y);
		}
		w = min(w, bmax - bmin);

		ret = min(ret, (rmax - rmin) * w);
	}
	{
		i64 rmax = X[lp];
		i64 rmin = X[sp];
		i64 bmax = Y[lp];
		i64 bmin = Y[sp];
		for (int i = 0; i < N; ++i) {
			rmax = max(rmax, X[i]);
			bmin = min(bmin, Y[i]);
		}
		ret = min(ret, (rmax - rmin) * (bmax - bmin));
	}
	printf("%lld\n", ret);
	return 0;
}
