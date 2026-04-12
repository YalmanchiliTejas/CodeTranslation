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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int ans[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string str;
	cin >> n;
	cin >> str;
	for (int o1 = 0; o1 < 2; o1++)
	{
		for (int o2 = 0; o2 < 2; o2++)
		{
			ans[0] = o1;
			ans[1] = o2;
			for (int i = 1; i < n; i++)
			{
				if (ans[i] == 0)
				{
					if (str[i] == 'o') ans[(i + 1) % n] = ans[i - 1];
					else ans[(i + 1) % n] = ans[i - 1] ^ 1;
				}
				else
				{
					if (str[i] == 'o') ans[(i + 1) % n] = ans[i - 1] ^ 1;
					else ans[(i + 1) % n] = ans[i - 1];
				}
			}
			if (ans[0] != o1) continue;
			if ((ans[n - 1] == ans[1]) ^ (str[0] == 'o') ^ (ans[0] != 0)) continue;
			for (int i = 0; i < n; i++) putchar("SW"[ans[i]]);
			puts("");
			return 0;
		}
	}
	puts("-1");
	return 0;
}