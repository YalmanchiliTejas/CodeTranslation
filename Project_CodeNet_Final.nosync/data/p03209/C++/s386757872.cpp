#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
LL p[N];
LL tot[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	p[0] = 1;
	for (int i = 1; i < N; i++) p[i] = p[i - 1] * 2 + 1;
	tot[0] = 1;
	for (int i = 1; i < N; i++) tot[i] = tot[i - 1] * 2 + 3;
	int n;
	LL x;
	cin >> n >> x;
	LL ans = 0;
	while (n >= 0)
	{
		if (n == 0)
		{
			ans++;
			break;
		}
		LL l = 1, r = tot[n];
		LL mid = (r + 1) / 2;
		if (x >= mid) ans += p[n - 1] + 1;
		if (x == r) ans += p[n - 1];
		if (x == l || x == mid || x == r) break;
		if (x > mid) x -= mid;
		else x--;
		n--;
	}
	cout << ans << endl;
	return 0;
}