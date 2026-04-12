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
const int N = 5e3 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	map<char, int> mc;
	int n;
	cin >> n;
	for (int i = 'a'; i <= 'z'; i++) mc[i] = INF;
	while (n--)
	{
		string str;
		cin >> str;
		map<char, int> mc2;
		for (auto& c : str) mc2[c]++;
		for (int i = 'a'; i <= 'z'; i++) mc[i] = min(mc[i], mc2[i]);
	}
	for (int i = 'a'; i <= 'z'; i++)
	{
		while (mc[i]--)
			putchar(i);
	}
	puts("");
	return 0;
}