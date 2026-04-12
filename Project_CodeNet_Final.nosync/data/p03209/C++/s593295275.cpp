#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <array>
#include <list>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define SZ 100001

int N;
ll arr[51], p[51], X;

ll func(ll N, ll X) {
	if (N == 0) return (X > 0 ? 1 : 0);
	if (X <= 1 + arr[N - 1]) return func(N - 1, X - 1);
	return p[N - 1] + 1 + func(N - 1, X - 2 - arr[N - 1]);

}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> X;

	arr[0] = p[0] = 1;
	for (int i = 1; i <= N; ++i) {
		arr[i] = arr[i - 1] * 2 + 3;
		p[i] = p[i - 1] * 2 + 1;
	}

	cout << func(N, X);

}