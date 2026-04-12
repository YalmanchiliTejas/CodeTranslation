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
#include <list>
#include <bitset>

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

template <class T, class U>
istream& operator>>(istream& ist, pair<T, U>& right) { return ist >> right.first >> right.second; }
template <class T, class U>
ostream& operator<<(ostream& ost, pair<T, U>& right) { return ost << right.first << ' ' << right.second; }
template <class T, class TCompatible, size_t N>
void Fill(T(&dest)[N], const TCompatible& val) { fill(begin(dest), end(dest), val); }
template <class T, class TCompatible, size_t M, size_t N>
void Fill(T(&dest)[M][N], const TCompatible& val) { for (int i = 0; i < M; ++i) Fill(dest[i], val); }

#if 1
#include <array>
#include <unordered_set>
#include <unordered_map>
template<class T>
using PriorityQ = priority_queue<T, vector<T>, greater<T> >;	// コスト小を優先
#endif


int N;
list<int> L;
int main() {
	cin >> N;
	REP(i, 0, N) {
		int a;
		cin >> a;
		if ((N - i) % 2 == 0) {
			L.push_back(a);
		} else {
			L.push_front(a);
		}
	}
	for (auto it = L.begin(); it != L.end(); ++it) {
		cout << *it << (it != prev(L.end()) ? ' ' : '\n');
	}
	return 0;
}