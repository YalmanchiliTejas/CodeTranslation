#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cfloat>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <list>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
#define int long long
#define ll long long
#define eps LDBL_EPSILON
#define mod (int)1000000007
#define DBLINF (DBL_MAX)/10
#define P pair<int,int>
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define all(V) V.begin(),V.end()
#ifdef int
constexpr int INF = LLONG_MAX / 10;
#else
constexpr int INF = INT_MAX / 10;
#endif
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
using namespace std;
inline int gcd(int a, int b) {
	while (b) {
		int c = a;
		a = b; b = c % b;
	}
	return a;
}
inline int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}
bool isprime(int n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
int mypow(int a, int b) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a;
	int memo = mypow(a, b >> 1);
	return memo * memo;
}
int modpow(int a, int b, int m = mod) {
	if (!b)return 1;
	if (b & 1)return modpow(a, b - 1, m) * a % m;
	int memo = modpow(a, b / 2, m);
	return memo * memo % m;
}
int n, a, b, cnt[100010], parent[100010];
vector<int> vec[100010];
bool used[100010];
queue<int> leaf;
void dfs(int node) {
	used[node] = true;
	bool isparent = false;
	for (int i : vec[node]) {
		if (!used[i]) {
			isparent = true;
			parent[i] = node;
			dfs(i);
		}
	}
	if (!isparent) {
		leaf.push(node);
	}
}
signed main() {
	cin >> n;
	if (n % 2) {
		puts("First");
		return 0;
	}
	rep(i, n - 1) {
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
		cnt[a]++; cnt[b]++;
	}
	dfs(1);
	fill(used + 1, used + n + 1, false);
	while (!leaf.empty()) {
		int node = leaf.front();
		leaf.pop();
		if (node == 1 || used[parent[node]]) {
			puts("First");
			return 0;
		}
		used[node] = true;
		used[parent[node]] = true;
		if (parent[node] != 1 && !used[parent[parent[node]]]) {
			cnt[parent[parent[node]]]--;
			if (cnt[parent[parent[node]]] == 1) {
				leaf.push(parent[parent[node]]);
			}
		}
	}
	REP(i, n) {
		if (!used[i]) {
			puts("First");
			return 0;
		}
	}
	puts("Second");
	return 0;
}