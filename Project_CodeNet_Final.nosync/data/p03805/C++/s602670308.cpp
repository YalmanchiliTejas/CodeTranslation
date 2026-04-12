#define _CRT_SECURE_NO_WARNINGS

// When you are using the gcc compiler, you need only the following lines.
// #include <bits/stdc++.h>

// When you are using other compilers, you need the following line instead.
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

// competitive macro
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i ,n) for (int i = (n) - 1; i >= 0; i--)
#define LL long long
#define ULL unsigned long long

const int nmax = 8;
//vector<vector<bool>> graph;
array<array<bool, nmax>, nmax> graph;

int dfs(int v, int n, array<bool, nmax> visited)
{
	bool all_visited = true;

	REP(i, n)
	{
		if (visited[i] == false) all_visited = false;
	}

	if (all_visited) return 1;

	int ret = 0;

	REP(i, n)
	{
		if (graph[v][i] == false) continue;
		if (visited[i]) continue;

		visited[i] = true;
		ret += dfs(i, n, visited);
		visited[i] = false;
	}

	return ret;
}

int main()
{
	int n, m;
	//cin >> n, m;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; i++)//REP(i, m)
	{
		int A, B;
		//cin >> A >> B;
		scanf("%d%d", &A, &B);
		graph[A - 1][B - 1] = true;
		graph[B - 1][A - 1] = true;
	}

	array<bool, nmax> visited;
	REP(i, n)
		visited[i] = false;

	visited[0] = true;
	//cout << dfs(0, n, visited) << endl;
	printf("%d\n", dfs(0, n, visited));
}