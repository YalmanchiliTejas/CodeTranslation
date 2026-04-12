#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
vector<int> tree[101010];

int solve(int p, int rt)
{
	int ans = 1;
	for (int q : tree[p]) if (q != rt) {
		int v = solve(q, p);
		if (v == -1) return -1;
		ans -= v;
	}

	if (ans < 0) return -1;
	return ans;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a; --b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	puts(solve(0, -1) == 0 ? "Second" : "First");

	return 0;
}
