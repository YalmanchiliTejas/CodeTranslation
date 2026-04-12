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
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int, int>> vp;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] = INF - a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		auto iter = lower_bound(vp.begin(), vp.end(), make_pair(a[i], i));
		if (iter == vp.end()) vp.emplace_back(a[i], i);
		else *iter = make_pair(a[i], i);
	}
	cout << vp.size() << endl;
	return 0;
}