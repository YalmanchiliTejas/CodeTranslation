#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <climits>

using namespace std;

uint64_t count_p(int l, uint64_t p, const vector<uint64_t> pnum, const vector<uint64_t> bnum, const vector<uint64_t> sum)
{
	assert(p <= sum[l]);
	if (l == 0) {
		return 1;
	}
	if (p <= 1) {
		return 0;
	}
	if (p >= sum[l] - 1) {
		return pnum[l];
	}

	uint64_t spos = 0;
	bool     is_rev = false;

	if (p == sum[l] / 2 + 1) {
		return pnum[l] / 2 + 1;
	}
	
	if (p > sum[l] / 2 + 1) {
		spos = sum[l] - p;
		is_rev = true;
	}
	else {
		spos = p;
	}

	uint64_t num = count_p(l - 1, spos - 1, pnum, bnum, sum);
	uint64_t ret = is_rev ? pnum[l] - num : num;
	return ret;
}

int main()
{
	int l; uint64_t p; cin >> l >> p;

	// 総数
	vector<uint64_t> pnum(l + 1);
	vector<uint64_t> bnum(l + 1);
	vector<uint64_t>  sum(l + 1);
	pnum[0] = 1; bnum[0] = 0; sum[0] = 1;
	{
		for (int i = 1; i <= l; i++) {
			pnum[i] = (pnum[i-1] * 2) + 1;
			bnum[i] = (bnum[i-1] * 2) + 2;
			sum[i] = bnum[i] + pnum[i];
		}
	}

	uint64_t val = count_p(l, p, pnum, bnum, sum);

	cout << val << endl;

	return 0;
}