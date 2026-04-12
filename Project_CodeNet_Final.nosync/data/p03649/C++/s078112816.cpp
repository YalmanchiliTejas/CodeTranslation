
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <array>
#include <cassert>
#include <bitset>
using namespace std;
using LL = long long;

LL N;
vector<LL>a;
//x回でできるか？
bool cond(LL x, vector<LL>A)
{
	for (LL&elm : A)elm += x;
	LL cnt = 0;
	for (LL elm : A)
	{
		elm -= (N - 1);
		if (elm <= 0)continue;
		cnt += (elm - 1) / (N + 1) + 1;
	}
	return cnt <= x;
}

int main(void)
{
	cin >> N;
	LL sum = 0;
	for (int i = 0; i < N; ++i)
	{
		LL aa; cin >> aa;
		a.push_back(aa);
		sum += (aa - (N - 1));
	}
	if (cond(0, a))
	{
		cout << 0 << endl;
		return 0;
	}
	LL small = sum;
	small = max(small, 0LL);
	for (LL x = small; true; ++x)
	{
		if (cond(x, a))
		{
			cout << x << endl;
			return 0;
		}
	}
	return 0;
}
