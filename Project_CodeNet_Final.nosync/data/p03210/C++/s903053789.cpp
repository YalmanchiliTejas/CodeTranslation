#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

#define _CRT_SECURE_NO_WARNINGS
#define REP(i, n) for(int i=0; i<n; i++)
#define FOR(i, m, n) for(int i=m; i<n; i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 999999999

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

int main() {
	
	int x;
	cin >> x;
	if (x == 3 || x == 5 || x == 7)puts("YES");
	else puts("NO");
}