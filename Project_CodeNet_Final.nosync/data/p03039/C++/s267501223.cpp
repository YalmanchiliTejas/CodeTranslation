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
const int N = 2e5 + 10;
LL rev[N];
void init()
{
	rev[0] = rev[1] = 1;
	for (int i = 2; i < N; i++) rev[i] = (INF - INF / i) * rev[INF % i] % INF;
}
LL C(LL n, int m)
{
	LL ans = 1;
	while (m)
	{
		ans = ans * n % INF * rev[m] % INF;
		n--, m--;
	}
	return ans;
}
LL solve(vector<int>& v)
{
	sort(v.begin(), v.end());
	LL ans = 0;
	LL sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		ans = (ans + 1LL * v[i] * i - sum) % INF;
		sum += v[i];
		if (sum >= INF)
			sum -= INF;
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	vector<int> v1, v2;
	int n, m;
	cin >> n >> m;
	int k;
	cin >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			v1.push_back(i);
			v2.push_back(j);
		}
	}
	LL ans = (solve(v1) + solve(v2)) * C(1LL * n * m - 2, k - 2) % INF;
	if (ans < 0) ans += INF;
	cout << ans << endl;
	return 0;
}