#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <string>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define MAX_N 100000
int par[MAX_N];
int rnk[MAX_N];
struct point { int index; int X; int Y; };
struct edge { point st; point fin; };
vector <point> p;
vector <edge> e;
void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		rnk[i] = 0;
	}
}
int find(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = find(par[x]);
	}
}
void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rnk[x] < rnk[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}
bool same(int x, int y) {
	return find(x) == find(y);
}
int norm(edge E) {
	return min({abs(E.st.X-E.fin.X),abs(E.st.Y-E.fin.Y)});
}
bool lessX(const point& p1, const point& p2) { return (p1).X < (p2).X; };
bool lessY(const point& p1, const point& p2) { return (p1).Y < (p2).Y; };
int main(void) {
	int N;
	cin >> N;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		p.push_back({ i,x,y });
	}
	sort(p.begin(), p.end(), lessX);
	int k = 0;
	for (int i = 1; i < N; i++) {
		e.push_back( {p[i - 1], p[i] });
		k++;
	}
	sort(p.begin(), p.end(), lessY);
	for (int i = 1; i < N; i++) {
		e.push_back({ p[i - 1],p[i] });
		k++;
	}
	sort(e.begin(), e.end(), [](edge e1, edge e2) {return norm(e1) < norm(e2); });
	int ans = 0;
	init(N);
	for (int i = 0; i < 2 * N - 2; i++) {
		if (!(same(e[i].st.index, e[i].fin.index))) {
			unite(e[i].st.index, e[i].fin.index);
			ans += norm(e[i]);
		}
	}
	cout << ans << endl;
	return 0;
}