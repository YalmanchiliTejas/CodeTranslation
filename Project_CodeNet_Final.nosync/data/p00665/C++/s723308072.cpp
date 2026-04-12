#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>

using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


struct Chara
{
	int p;
	string name;
	Chara(string name, int p)
		: name(name), p(p) {}
};
bool operator<(const Chara& a, const Chara& b)
{
	return a.p > b.p || a.p == b.p && a.name < b.name;
}
const int MAX = 114514;
vector<Chara> chara;
bool fav[MAX];
int sum[MAX];
int n, m, k, l;
bool can(int p)
{
	int insert = -1;
	for (int i = k; i >= 0 && insert == -1; --i)
		if (sum[i] + k - i >= p)
			insert = i;
	if (insert == -1)
		return false;
	else if (sum[insert] >= p)
		return true;

	int need = p - sum[insert];
	int left = l;
	for (int i = insert; i < n && need > 0 && left > 0; ++i)
	{
		if (fav[i])
		{
			--need;
			left -= (chara[insert].p - chara[i].p)
				+ (chara[insert].name < chara[i].name ? 1 : 0);
		}
	}
	return need == 0 && left >= 0;
}
int main()
{
	while (scanf("%d%d%d%d", &n, &m, &k, &l), n)
	{
		char buf[16];
		chara.clear();
		rep (i, n)
		{
			int t;
			scanf("%s%d", buf, &t);
			chara.push_back(Chara(buf, t));
		}
		set<string> f;
		rep (i, m)
		{
			scanf("%s", buf);
			f.insert(buf);
		}
		sort(all(chara));


		sum[0] = 0;
		rep (i, n)
		{
			int t = f.count(chara[i].name);
			fav[i] = t == 1;
			sum[i + 1] = sum[i] + t;
		}


		int low = 0, high = k + 1;
		while (low + 1 < high)
		{
			int mid = (low + high) / 2;
			if (can(mid))
				low = mid;
			else
				high = mid;
		}
		printf("%d\n", low);
	}
}