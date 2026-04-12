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
const int N = 1e5 + 10;
const int M = 333;
vector<int> v[N];
LL pre[N][M];
int a[N];
void init()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = i; j < N; j += i)
			v[j].push_back(i);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 1; j < M && i + j < n; j++)
		{
			pre[i][j] = pre[i + j][j] + a[i];
		}
	}
	LL ans = 0;
	for (int i = 1; i < n - 1; i++)
	{
		int rest = n - 1 - i;
		for (auto& delta : v[rest])
		{
			int A = i;
			int B = A - delta;
			if (B <= 0) break;
			int cur1 = A;
			int cur2 = A - B;
			if (B % delta == 0 && A + B < n - 1) continue;
			LL sum = 0;
			if (delta < M)
			{
				sum += pre[cur1][delta] + pre[cur2][delta] - pre[cur2 + rest][delta];
			}
			else
			{
				while (cur1 < n - 1)
				{
					sum += a[cur1] + a[cur2];
					cur1 += delta;
					cur2 += delta;
				}
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}