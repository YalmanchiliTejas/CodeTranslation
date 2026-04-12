//#include "IntMod.h"
//typedef IntMod<1000000007> MInt;

//#include "Union_Find.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <array>

using namespace std;
#define REP(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define REPM(i,n,a) for(int i = ((n) - 1); i >= (a); --i)
#define EPS 0.0001
#define INF 0x3FFFFFFF
#define INFLL 0x3FFFFFFF3FFFFFFF
#define INFD 1.0e+308
#define FLOAT setprecision(16)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PP;

#if 1
#include <unordered_set>
#include <unordered_map>
template<typename T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif

int a, s, d;
int main() {
	cin >> a >> s >> d;
	cout << ((s * 10 + d) % 4 == 0 ? "YES" : "NO") << endl;
	return 0;
}