
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

typedef unsigned long long ULLONG;
typedef long long LLONG;
static const LLONG MOD_NUM = 1000000007;

template <class _T> static _T tp_abs(const _T& a) {
	//	usage:  tp_abs<type name>(a);
	return ((a < 0) ? (a * -1) : a);
}
template <class _T> static _T tp_min(_T a, _T b) {
	return a < b ? a : b;
}
template <class _T> static _T tp_max(_T a, _T b) {
	return a > b ? a : b;
}
template<class _T> static void get1int(_T& a) {
	const char* fmt = " %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld";
	}

	if (scanf(fmt, &a) < 0) {
		printf("g1int Error\n");
	}
}
template<class _T> static void get2int(_T& a, _T& b) {
	const char* fmt = " %d %d";
	if (sizeof(_T) == sizeof(long long)) {
		fmt = " %lld %lld";
	}

	if (scanf(fmt, &a, &b) < 0) {
		printf("g2int Error\n");
	}
}
static void getstring(char* buff) {
	if (scanf(" %s", buff) < 0) {
		printf("getstr error!\n");
	}
}

static void ABC054C_OneStrokePath();

#if 1
int main()
{
	ABC054C_OneStrokePath();
	fflush(stdout);
	return 0;
}
#endif

static int ABC054C_dfs(std::set<int> visit, std::vector<std::vector<int>>& graph, int now, int vCnt) 
{
	if (visit.find(now) != visit.end()) {
		return 0;
	}
	visit.insert(now);
	if (visit.size() == vCnt) {
		return 1;
	}

	int ans = 0;
	for (auto it = graph[now].begin(); it != graph[now].end(); it++) {
		ans += ABC054C_dfs(visit, graph, *it, vCnt);
	}
	return ans;
}
static void ABC054C_OneStrokePath()
{
	int N, M;
	get2int(N, M);

	std::vector<std::vector<int>> edge(N);
	for (int i = 0; i < M; i++) {
		int from, to;
		get2int(from, to); from--; to--;
		edge[from].push_back(to);
		edge[to].push_back(from);
	}

	std::set<int> visit;
	printf("%d\n", ABC054C_dfs(visit, edge, 0, N));
}
